#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool hasLRSOfLength(const string& s, int len, string& result) {
    int length = s.length();
    unordered_map<string, int> uMap;
    
    for(int i = 0; i <= length - len; i++) {
        string substring = s.substr(i, len);
        
        if(uMap.count(substring)) {

            if(i >= uMap[substring] + len) {
                if(result.empty()||substring < result) {
                    result = substring;
                }
            }
        } else {
            uMap[substring] = i;
        }
    }
    
    return !result.empty();
}

string longestRepeatedSub(const string& s) {
    int length = s.length();

    int left = 1;
    int right = length/2;
    int max = 0;
    string result = "";
    

    while(left <= right) {
        int middle = (left+right)/2;
        string candidate = "";

        if(hasLRSOfLength(s, middle, candidate)) {
            max = middle;
            result = candidate;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }


    return result;
}

int main() {
    
    string s;

    while(getline(cin, s)) {
        if(s.size() == 0) {
            continue;
        }

        string findLrs = longestRepeatedSub(s);

        if(findLrs.empty()) {
            cout << "No LRS is found." << endl;
        } else {
            cout << findLrs << endl;
        }
    }

    return 0;
}