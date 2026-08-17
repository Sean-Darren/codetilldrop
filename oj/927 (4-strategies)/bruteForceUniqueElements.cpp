#include <iostream>
#include <sstream>
using namespace std;

void bruteForceMethod(const string& line) {
    int numberInArray[100000];
    int indexOfArray = 0;
    int num;

    istringstream iss(line);
    
    while(iss >> num) {
        numberInArray[indexOfArray++] = num;
    }

    bool isFirstElement = true;
    for(int i = 0 ; i < indexOfArray ; i++) {
        int count = 0;

        for(int j = 0 ; j < indexOfArray ; j++) {
            if (numberInArray[i] == numberInArray[j]) {
                count++;
            }
        }

        if(count == 1) {
            if(!isFirstElement) {
                cout << " ";
            }
            cout << numberInArray[i];
            isFirstElement = false;
        }
    }

    cout << endl;
}

int main() {

    string line;
    while(getline(cin, line)) {
        if(line.empty()) {
            continue;
        }

        bruteForceMethod(line);
    }


    return 0;
}