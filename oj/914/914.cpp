#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int minimumLetterMoves(char c) {
    int forward = c - 'A';
    int backward = 26 - forward;

    int minimumFB = min(forward, backward);
    return minimumFB;
}

int joyStickMoves(string line) {
    int num = line.length();
    int totalLetterMoves = 0;

    for(int i = 0 ; i < num ; i++){
        totalLetterMoves += minimumLetterMoves(line[i]);
    }

    bool allA = true;
    for (int i = 0; i < num; i++) {
        if (line[i] != 'A') {
            allA = false;
            break;
        }
    }

    if(allA){
        return 0;
    }
    
    int minimumOfCursorMoves = num - 1;
    for(int i = 0 ; i < num ; i++) {
        if(line[i] != 'A') {
            int j = i + 1;
            while(j < num && line[j] == 'A') {
                j++;
            }

            if(j < num) {
                int rightThenLeft = 2 *i + (num - j);
                int leftThenRight = 2*(num - j) + i;

                minimumOfCursorMoves = min({minimumOfCursorMoves, rightThenLeft, leftThenRight});
            } else {
                minimumOfCursorMoves = min(minimumOfCursorMoves, i);
            }
        }
    }

    int totalMoves = minimumOfCursorMoves + totalLetterMoves;

    return totalMoves;

}

int main() {

    int numberOfTestCase;
    cin >> numberOfTestCase;

    while(numberOfTestCase --) {
        string lineChar;
        cin >> lineChar;

        cout << joyStickMoves(lineChar) << endl;
    }
}