#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ElementBoringJob {
    int value;
    int oriIndex;
};

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int n, k;
        cin >> n >> k;
        
        vector<ElementBoringJob> magicSequence;
        for(int i = 0 ; i < n ; i++) {
            int value;
            cin >> value;
            magicSequence.push_back(ElementBoringJob{value, i+1});
        }

        vector<int> result;

        while(!magicSequence.empty()) {
            int count = min(k, (int)magicSequence.size());

            vector<ElementBoringJob> temp;
            for(int i = 0 ; i < count ; i++) {
                temp.push_back(magicSequence[i]);
            }

            magicSequence.erase(magicSequence.begin(), magicSequence.begin() + count);

            int max = 0;
            for(int i = 0; i < temp.size(); i++) {
                if(temp[i].value > temp[max].value) {
                    max = i;
                } 
            }

            result.push_back(temp[max].oriIndex);

            for(int i = 0 ; i < temp.size() ; i++) {
                if(i != max) {
                    temp[i].value = temp[i].value - 1;
                    magicSequence.push_back(temp[i]);
                }
            }
        }

        bool isFirst = true;
        for(int i = 0 ; i < result.size() ; i++) {
            if(!isFirst) {
                cout << " ";
            }
            cout << result[i];
            isFirst = false;

        }
        cout << endl;
    }

    return 0;
}
