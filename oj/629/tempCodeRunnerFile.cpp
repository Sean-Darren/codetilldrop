#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool hasNonOverlapping(const string& s, const vector<int>& position, int leng) {
    for(int i = 0; i < position.size(); i++) {
        for(int j = i + 1; j<position.size(); j++) {
             if (position[j] - position[i] >= leng) {
                if (s.compare(position[i], leng, s, position[j],leng) == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

string checkTheLength(const string& s, int len) {
    int length = s.length();

    if (len > length / 2 || len == 0) {
        return "";
    }

    const long long baseNum = 31;
    const long long mod = 1e9 + 7;
    long long powOfBase = 1;
    for(int i = 0; i < len -1 ; i++) {
        powOfBase = (powOfBase * baseNum) % mod;
    }

    long long hashNum = 0;
    for(int i = 0 ; i < len ; i++) {
        hashNum = (hashNum * baseNum + ((unsigned char)s[i])) % mod;
    }

    unordered_map<long long, vector<int>> hashM;
    hashM[hashNum].push_back(0);
    for(int i = 1 ; i <= length - len ;i++) {
        hashNum = (hashNum - ((unsigned char)s[i - 1]) * powOfBase % mod + mod) % mod;
        hashNum = (hashNum * baseNum + ((unsigned char)s[i + len - 1] - 'A' + 1))%mod;
        hashM[hashNum].push_back(i);
    }


    string result = "";
    for(auto& pair: hashM) {
        vector<int>& position = pair.second;
        if(position.size() < 2) { continue;}

        sort(position.begin(), position.end());

        if(hasNonOverlapping(s, position, len)) {
            string tempSubStr = s.substr(position[0], len);
            if (result.empty() || tempSubStr < result) {
                result =tempSubStr;
            }
        }
    }
    return result;

}

string longestRepeatedSub(const string& s) {
    int length = s.length();

    int left = 1;
    int right = length/2;

    string result = "" ;
    while(left <= right) {
        int middle = (left+right)/2;
        string checkTemp = checkTheLength(s, middle);

        if(checkTemp.empty() == false) {
            result = checkTemp;
            left = middle + 1;
        } else {
            right = middle -1;
        }
    }

    return result;
}

int main() {
    string s;

    while(cin>>s) {
        string findLrs = longestRepeatedSub(s);

        if(findLrs.empty()) {
            cout << "No LRS is found." << endl;
        } else {
            cout << findLrs << endl;
        }
    }

    return 0;
}