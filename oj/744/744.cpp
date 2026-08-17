#include <iostream>
#include "stdlib.h"
#include <vector>
using namespace std;

class MyStack {
    private:
        int*data;
        int top;
        int maxSize;
    public:
        MyStack(int size) {
            maxSize = size;
            data = new int[size];
            top = -1;
        }

        ~MyStack() {
            delete[] data;
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == maxSize - 1);
        }

        void push(int x) {
            if(!isFull()){
                top++;
                data[top] = x;
            }
        }

        int pop() {
            int returnVal;
            if(!isEmpty()){
                returnVal = data[top];
                top--;
                return returnVal;
            } else {
                return -1;
            }
        }

        int getTop() {
            if(!isEmpty()){
                return(data[top]);
            } else {
                return -1;
            }
        }

        int getSize() {
            return maxSize;
        }

        void print(){
            for(int i = 0; i <= top; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }            
};

int main() {

    int testCase;
    cin >> testCase;
    

    while(testCase--){
        int numElements;
        cin >> numElements;

        MyStack stackS(numElements);

        vector<int> stackA(numElements);
        for (int i = 0; i < numElements; i++) {
            cin >> stackA[i];
        }

        int permutations;
        cin >> permutations;

        vector<string> results;

        for(int p = 0 ; p < permutations ; p++){
            vector<int> target(numElements);

            for(int i = 0; i < numElements; i++){
                cin >> target[i];
            }

            MyStack stackS(numElements);
            int pos = 0;

            for (int i = numElements - 1; i >= 0; i--) {
                stackS.push(stackA[i]);
                while (!stackS.isEmpty() && stackS.getTop() == target[pos]) {
                    stackS.pop();
                    pos++;
                }
            }

            if(pos == numElements){
                results.push_back("Aye");
            } else {
                results.push_back("Impossible");
            }

        }

        for(int i = 0 ; i < permutations ; i++){
            cout << results[i] << endl;
        }

    }
    return 0;
}
