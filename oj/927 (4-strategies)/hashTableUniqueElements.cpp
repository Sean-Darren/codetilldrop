#include <iostream>
#include <sstream>
using namespace std;

const int HASH_SIZE = 200003;

struct HashNode {
    int keyActualNumber;
    int countNumbers;
    bool isOccupied;
};

class HashTable {
    private:
        HashNode table[HASH_SIZE];

        int hash(int keyNumber) {
            int index = keyNumber % HASH_SIZE;

            if (index < 0) {
                index += HASH_SIZE;
            }

            return index;
        }

    public: 
        
        HashTable() {
            for (int i = 0; i < HASH_SIZE; i++) {
                table[i].isOccupied = false;
                table[i].countNumbers = 0;
            } 
        }

        void insertNumber(int keyNumber) {
            int index = hash(keyNumber);

            while(table[index].isOccupied && table[index].keyActualNumber != keyNumber) {
                index = (index + 1) % HASH_SIZE;
            }

            if(table[index].isOccupied) {
                table[index].countNumbers++;
            } else {
                table[index].keyActualNumber = keyNumber;
                table[index].countNumbers = 1;
                table[index].isOccupied = true;
            }
        }

        int getCount(int keyNumber) {
            int index = hash(keyNumber);

            while(table[index].isOccupied) {
                if(table[index].keyActualNumber == keyNumber) {
                    return table[index].countNumbers;
                }

                index = (index + 1) % HASH_SIZE;
            }
            
            return 0;
        }

};

void usingHashTable(const string& line) {
    int numberInArray[100000];
    int indexOfArray = 0;
    int num;

    istringstream iss(line);
    
    while(iss >> num) {
        numberInArray[indexOfArray++] = num;
    }

    HashTable hashTable;

    for(int i = 0 ; i < indexOfArray ; i++) {
        hashTable.insertNumber(numberInArray[i]);
    }

    bool isFirstElement = true;
    for (int i = 0 ; i < indexOfArray ; i++) {
        if(hashTable.getCount(numberInArray[i]) == 1) {
            if (!isFirstElement) cout << " ";
            cout << numberInArray[i];
            isFirstElement = false;
        }
    }
    cout << endl;
};

int main() {

    string line;
    while(getline(cin, line)) {
        if(line.empty()) {
            continue;
        }

        usingHashTable(line);
    }

    return 0;
}