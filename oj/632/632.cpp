#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int numOfTC;
    cin >> numOfTC;

    int nWeapons, kUnits;
    for(int i = 0 ; i < numOfTC ; i++) {
        cin >> nWeapons >> kUnits;

        int weightList[1000];

        for(int i = 0 ; i < nWeapons ; i++) {
            cin >> weightList[i];
        }

        for(int i = 0 ; i < nWeapons - 1 ; i++) {
            for(int j = 0 ; j < nWeapons - i - 1 ; j++) {
                if(weightList[j] > weightList[j+1]) {
                    int temp = weightList[j];
                    weightList[j] = weightList[j+1];
                    weightList[j+1] = temp;
                }
            }
        }

        int countNum = 0;
        int totalOfWeight = 0;

        for(int i = 0 ; i < nWeapons ; i++) {
            if(totalOfWeight + weightList[i] <= kUnits){
                totalOfWeight += weightList[i];
                countNum++;
            } else {
                break;
            }
        }

        cout << countNum << endl;


    }

    return 0;
}