#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

set<vector<int>> toCut, toKeep;

int countToCut(vector<int> thePrefix) {
    set<vector<int>> underCut, underKeep;

    for(auto& thePath: toCut){
        if(thePath.size() > thePrefix.size()) {
            bool isMatch = true;
            for(int i = 0 ; i < thePrefix.size() ; i++) {
                if(thePath[i] != thePrefix[i]) {
                    isMatch = false;
                    break;
                }
            }

            if(isMatch) {underCut.insert(thePath);}
        } else if(thePath == thePrefix) {
            underCut.insert(thePath);
        }
    }

    for(auto& thePath: toKeep) {
        if(thePath.size() > thePrefix.size()) {
            bool isMatch = true;
            for(int i = 0 ; i < thePrefix.size() ; i++) {
                if(thePath[i] != thePrefix[i]) {
                    isMatch = false;
                    break;
                }
            }

            if(isMatch) {underKeep.insert(thePath);}
        } else if(thePath == thePrefix) {
            underKeep.insert(thePath);
        }
    }

    if(underCut.size() == 0) {return 0;}

    for(auto& thePath: underKeep) {
        if(thePath == thePrefix) {
            set<int> nextNode;

            for(auto& thePath: underCut) {
                if(thePath.size() > thePrefix.size()) {
                    nextNode.insert(thePath[thePrefix.size()]);
                }
            }

            for(auto& thePath: underKeep) {
                if(thePath.size() > thePrefix.size()) {
                    nextNode.insert(thePath[thePrefix.size()]);
                }
            }

            int theTotal = 0;
            for(int theNode: nextNode) {
                vector<int> newPrefix = thePrefix;
                newPrefix.push_back(theNode);
                theTotal += countToCut(newPrefix);
            }

            return theTotal;
        }
    }

    for(auto& thePath: underCut) {
        if(thePath == thePrefix) {return 1;}
    }

    for(auto& thePath: underKeep) {
        if(thePath == thePrefix) { return 1; }
    }

    if(underKeep.size() == 0 && thePrefix.size() != 0) { 
        return 1; 
    }

    set<int> nextNode;

    for(auto& thePath: underCut) {
        if(thePath.size() > thePrefix.size()) {
            nextNode.insert(thePath[thePrefix.size()]);
        }

    }

    for(auto& thePath: underKeep) {
        if(thePath.size() > thePrefix.size()) {
            nextNode.insert(thePath[thePrefix.size()]);
        }
        
    }

    int theTotal = 0;
    vector<int> newPrefix;
    for(int theNode: nextNode) {
        newPrefix = thePrefix;
        newPrefix.push_back(theNode);
        theTotal += countToCut(newPrefix);
    }

    return theTotal;
}

int main() {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int n;
        int m;
        cin >> n >> m;
        
        toCut.clear();
        toKeep.clear();

        for(int i = 0 ; i < n ; i++) {
            vector<int> thePath;
            int x;
            while(cin >> x){
                if(x == -1) {break;}

                thePath.push_back(x);
            }

            toCut.insert(thePath);
        }

        for(int i = 0 ; i < m ; i++) {
            vector<int> thePath;
            int x;
            while(cin >> x){
                if(x == -1) {break;}

                thePath.push_back(x);
            }

            toKeep.insert(thePath);
        }
        cout << countToCut({}) << endl;
    }

    return 0;
}