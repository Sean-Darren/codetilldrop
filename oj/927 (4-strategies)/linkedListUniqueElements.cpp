#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
    int count;

    Node(int value) {
        data = value;
        count = 1;
        next = nullptr;
    }
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        void insert(int value) {
            Node* current = head;

            while(current != nullptr) {
                if(current->data == value) {
                    current->count++;
                    return;
                }
                current = current->next;
            }

            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        int getCount(int value) {
            Node* current = head;

            while(current != nullptr) {
                if(current->data == value) {
                    return current->count;
                }
                current = current->next;
            }
            return 0;
        }

        void clear() {
            while(head != nullptr) {
                Node* temp = head;
                head = head->next;
                
                delete temp;
            }
        }
        
        ~LinkedList() {
            clear();
        }
};

void usingLinkedList(const string& line) {
    int numberInArray[100000];
    int indexOfArray = 0;
    int num;

    istringstream iss(line);
    
    while(iss >> num) {
        numberInArray[indexOfArray++] = num;
    }

    LinkedList linkedList;

    for(int i = 0 ; i < indexOfArray ; i++) {
        linkedList.insert(numberInArray[i]);
    }

    bool isFirstElement = true;
    for (int i = 0 ; i < indexOfArray ; i++) {
        if(linkedList.getCount(numberInArray[i]) == 1) {
            if (!isFirstElement) cout << " ";
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

        usingLinkedList(line);
    }

    return 0;
}