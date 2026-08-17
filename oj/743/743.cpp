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
            }
        }

        int getTop() {
            if(!isEmpty()){
                return(data[top]);
            }
        }

        int getSize() {
            return maxSize;
        }

        int getBottom() {
            if(!isEmpty()){
                return data[0];
            }
        }

        void print(){
            for(int i = 0; i <= top; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }            
};

bool isOpenBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isCloseBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

bool isMatch(char open, char close) {
    if(open == '[' && close == ']') {
        return true;
    } else if(open == '(' && close == ')') {
        return true;
    } else if(open == '{' && close == '}') {
        return true;
    } else {
        return false;
    }
}

int main() {
    string S;

    while(getline(cin, S)) {
        MyStack stack(S.length());

        int firstUnmatched = -1;

        for(int i = 0 ; i < S.length() ; i++) {
            char ch = S[i];

            if(isOpenBracket(ch)) {
                stack.push(i + 1);
            } else if(isCloseBracket(ch)) {
                if(stack.isEmpty()) {
                    cout << (i + 1) << endl;
                    firstUnmatched = i + 1;
                    break;
                } else {
                    int outIndex = stack.pop();
                    char openChar = S[outIndex-1];

                    if(!isMatch(openChar, ch)) {
                         cout << (i + 1) << endl;
                        firstUnmatched = i + 1;
                        break;
                    }
                }
            } 
        }

        if(firstUnmatched == -1){
            if(stack.isEmpty()) {
                cout << "Success" << endl;
            } else {
                cout << stack.getBottom() << endl;
            }
        }
    }

    

    return 0;
}
