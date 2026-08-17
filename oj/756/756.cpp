#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        vector<int> heapT;

        int parent(int i) {
            int parent = (i-1)/2;
            return parent;
        }

        int leftChild(int i) {
            int leftC = (2*i) + 1;
            return leftC;
        }

        int rightChild(int i) {
            int rightC = (2*i) + 2;
            return rightC;
        }

    public:
        
        void up(int i) {
            while(i > 0 && heapT[parent(i)] < heapT[i]) {
                swap(heapT[i], heapT[parent(i)]);
                i = parent(i);
            }
        }

        void down(int i) {
            int max = i;
            int leftC = leftChild(i);
            int rightC = rightChild(i);

            if(leftC < heapT.size() && heapT[leftC] > heapT[max]) {
                max = leftC;
            }

            if(rightC < heapT.size() && heapT[rightC] > heapT[max]) {
                max = rightC;
            }
            
            if(i != max) {
                swap(heapT[i], heapT[max]);
                down(max);
            }
        }

        void insert(int k) {
            heapT.push_back(k);
            up(heapT.size() - 1);
        }

        void pop() {
            if(heapT.empty()) {
                return;
            } else {
                heapT[0] = heapT.back();
                heapT.pop_back();

                if(heapT.empty() == false) {
                    down(0);
                }
            }
        }

        int getSum() {
            int sum = 0;
            for(int value: heapT) {
                sum += value;
            }
            return sum;
        }
};

int main() {
    int numOfTestCase;
    
    while(cin >> numOfTestCase) {
        MaxHeap heap;

        for(int i = 0 ; i < numOfTestCase ; i++) {
            char opChar;
            cin >> opChar;

            if(opChar == 'a') {
                int value;
                cin >> value;
                heap.insert(value);
            } else if (opChar == 'p') {
                heap.pop();
            } else {
                cout << heap.getSum() << endl;
            }
        }
    }

    

    return 0;
}