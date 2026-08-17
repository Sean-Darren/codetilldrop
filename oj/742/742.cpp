#include <iostream>
#include "stdlib.h"
#include <vector>
using namespace std;

struct Quadrant {
    int x, y, size;
};

class MyStack {
    private:
        Quadrant*data;
        int top;
        int maxSize;
    public:
        MyStack(int size) {
            maxSize = size;
            data = new Quadrant[size];
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

        void push(Quadrant x) {
            if(!isFull()){
                top++;
                data[top] = x;
            }
        }

        Quadrant pop() {
            Quadrant returnVal;
            if(!isEmpty()){
                returnVal = data[top];
                top--;
                return returnVal;
            } else {
                return {-1, -1, -1};
            }
        }

        Quadrant getTop() {
            if(!isEmpty()){
                return(data[top]);
            } else {
                return {-1,-1,-1};
            }
        }

        int getSize() {
            return maxSize;
        }
};

bool checkSameColor(vector<vector<int>>& img, int x, int y, int size) {
    int first = img[x][y];

    for(int i = x; i < x +size ; i++) {
        for(int j = y ; j < y+size ; j++) {
            if(img[i][j] != first) {
                return false;
            }
        }
    }

    return true;
}

int countQTNode(vector<vector<int>>& img, int n) {
    MyStack stack(10000);
    stack.push({0, 0, n});
    int count = 0;

    while(stack.isEmpty() == false) {
        Quadrant currentNode = stack.pop();

        int x = currentNode.x;
        int y = currentNode.y;

        int size = currentNode.size;
        count++;
        if(checkSameColor(img, x,y, size) == false) {

            int half = size /2;
            stack.push({x, y, half});                
            stack.push({x, y + half, half});
            stack.push({x + half, y, half}); 
            stack.push({x + half, y + half, half});  
        }
    }

    return count;
}

int main() {
    int testCase;

    while(cin >> testCase) {
        int n = 1 << testCase;

        vector<vector<int>> img(n, vector<int>(n));

        for(int i = 0; i < n; i++) {
            string sLine;
            cin >> sLine;

            for(int j = 0; j < n; j++) {
                img[i][j] = sLine[j] - '0';
            }
        }
        
        int result = countQTNode(img, n);

        
        cout << result << endl;
    }
}