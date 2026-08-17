#include <iostream> 
using namespace std;

int main() {
    int numberOfElementsInList;
    cin >> numberOfElementsInList;

    int list[2000];
    int elementSize = numberOfElementsInList; 

    for(int i = 0 ; i < numberOfElementsInList ; i++) {
        cin >> list[i];
    }

    int qOperations;
    cin >> qOperations;

    while(qOperations--) {
        int operationsNumber;
        cin >> operationsNumber;

        if (operationsNumber == 1) {
            int i, value;
            cin >> i >> value;

            for(int j = elementSize ; j > i ; j--) {
                list[j] = list[j-1];
            }

            list[i] = value;
            elementSize++;
        } else if (operationsNumber == 2) {
            int i;
            cin >> i;

            for(int j = i - 1 ; j < elementSize - 1; j++) {
                list[j] = list[j+1];
            }
            elementSize--;
        } else if(operationsNumber == 3) {
            int i, j;
            cin >> i >> j;

            i = i-1;
            j = j-1;

            while(i < j) {
                int temp = list [i];
                list[i] = list[j];
                list[j] = temp;
                i++;
                j--;
            }
        } else if(operationsNumber == 4) {
            int i;
            cin >> i;
            cout << list[i-1] << endl;
        }
    }

    return 0;
}