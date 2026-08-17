#include <iostream>
#include "stdlib.h"
#include <vector>
#include <algorithm>
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

        int getCurrentSize() {
            return top + 1;
        }

        void print(){
            for(int i = 0; i <= top; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }            
};

struct Point {
    long long x;
    
    long long y;

    Point(long long x = 0, long long y = 0) {
        this->x = x;
        this->y = y;
    }
};

Point sortingPoint;

long long crossProduct(const Point& O, const Point& A, const Point& B) {
    long long crossProduct = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);

    return crossProduct;
}

long long distanceTwoPoints(const Point& first, const Point& second) {
    long long distance = (first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y);

    return distance;
}

bool polarAngleSort(const Point& first, const Point& second) {
    long long crossProductResult = crossProduct(sortingPoint, first, second);

    if(crossProductResult == 0) {
        return distanceTwoPoints(sortingPoint, first) < distanceTwoPoints(sortingPoint, second);
    }

    return crossProductResult > 0;
}

vector<Point> convexHull(vector<Point>& po) {
    int size = po.size();

    int min = 0;
    for(int i = 1; i < size ; i++) {
        if(po[i].x < po[min].x || (po[i].x == po[min].x && po[i].y < po[min].y)) {
            min = i;
        }
    }

    swap(po[0], po[min]);

    sortingPoint = po[0];

    sort(po.begin() + 1, po.end(), polarAngleSort);

    int uniquePolarAngle = 1;
    for(int i = 1 ; i < size ; i++){
        while (i < size - 1 && crossProduct(sortingPoint, po[i], po[i + 1]) == 0) {
            i++;
        }
        po[uniquePolarAngle++] = po[i];
    }

    if(uniquePolarAngle < 3) { return po; }

    MyStack hull(uniquePolarAngle);

    hull.push(0);
    hull.push(1);
    hull.push(2);

    for(int i = 3 ; i < uniquePolarAngle ; i++) {
        int top = hull.pop();
        int nextTop = hull.getTop();

        while(hull.isEmpty() == false && crossProduct(po[nextTop], po[top], po[i]) <= 0) {
            top = nextTop;
            hull.pop();

            if(hull.isEmpty() == false) {
                nextTop = hull.getTop();
            }
        }

        hull.push(top);
        hull.push(i);
    }

    vector<Point> theResult;
    int hullSize = hull.getCurrentSize();
    vector<int> indices(hullSize);

    for(int i = hullSize -1 ; i >= 0 ;i--) {
        indices[i] = hull.pop();
    }

    for(int i = 0 ; i < hullSize ; i++) {
        theResult.push_back(po[indices[i]]);
    }

    return theResult;
}

int main() {

    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int num;
        cin >> num;
        
        vector<Point> points(num);
        for (int i = 0; i < num ; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        vector<Point> hull = convexHull(points);
        
        cout << hull.size() << endl;
        for (const Point& po : hull) {
            cout << po.x << " " << po.y << endl;
        }
    }
    

    return 0;
}
