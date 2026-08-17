#include <iostream>
#include <sstream> 
using namespace std;

struct TreeNode {
    int valueOfNode;
    int countNumbers;
    int height;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

class AVLTree {
    private: 
        TreeNode allNode[100000];
        int index;
        TreeNode* root;

        int getHeight(TreeNode* node) {
            if(node != nullptr) {
                return node->height;
            }
            return 0;
        }

        int getBalance(TreeNode* node) {
            if(node != nullptr) {
                return (getHeight(node->leftNode) - getHeight(node->rightNode));
            }
            return 0;
        }

        void updateHeight(TreeNode* node) {
            node->height = 1 + max(getHeight(node->leftNode), getHeight(node->rightNode));
        }

        TreeNode* createNode(int value) {
            allNode[index].valueOfNode = value;
            allNode[index].countNumbers = 1;
            allNode[index].height = 1;
            allNode[index].leftNode = nullptr;
            allNode[index].rightNode = nullptr;
            return &allNode[index++];
        }

        TreeNode* rotateRight(TreeNode* y) {
            TreeNode* x = y->leftNode;
            TreeNode* rightChild = x->rightNode;

            x->rightNode = y;
            y->leftNode = rightChild;

            updateHeight(y);
            updateHeight(x);

            return x;
        }

        TreeNode* rotateLeft(TreeNode* x) {
            TreeNode* y = x->rightNode;
            TreeNode* leftChild = y->leftNode;

            y->leftNode = x;
            x->rightNode = leftChild;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        TreeNode* insertHelper(TreeNode* node, int value) {
            if (node == nullptr){
                return createNode(value);
            }

            if(value == node->valueOfNode) {
                node->countNumbers++;
                return node;
            } else if(value < node->valueOfNode) {
                node->leftNode = insertHelper(node->leftNode, value);
            } else {
                node->rightNode = insertHelper(node->rightNode, value);
            }

            updateHeight(node);
            int balance = getBalance(node);

            if (balance > 1 && value < node->leftNode->valueOfNode) {
                return rotateRight(node);
            }

            if (balance < -1 && value > node->rightNode->valueOfNode) {
                return rotateLeft(node);
            }

            if (balance > 1 && value > node->leftNode->valueOfNode) {
                node->leftNode = rotateLeft(node->leftNode);
                return rotateRight(node);
            }

            if (balance < -1 && value < node->rightNode->valueOfNode) {
                node->rightNode = rotateRight(node->rightNode);
                return rotateLeft(node);
            }

            return node;
        }

        int getCountHelper(TreeNode* node, int value) {
            if (node == nullptr) {
                return 0;
            }

            if(value == node->valueOfNode) {
                return node->countNumbers;
            } else if(value < node->valueOfNode) {
                return getCountHelper(node->leftNode, value);
            } else {
                return getCountHelper(node->rightNode, value);
            }
        }

    public:
        AVLTree() {
            index = 0;
            root = nullptr;
        }

        void insert(int value) {
            root = insertHelper(root, value);
        }

        int getCount(int value) {
            int count = getCountHelper(root, value);

            return count;
        }
};

void usingAVLTree(const string& line) {
    int numberInArray[100000];
    int indexOfArray = 0;
    int num;

    istringstream iss(line);

    while(iss >> num) {
        numberInArray[indexOfArray++] = num;
    }

    AVLTree avlTree;

    for(int i = 0 ; i < indexOfArray ; i++) {
        avlTree.insert(numberInArray[i]);
    }

    bool isFirstElement = true;
    for (int i = 0 ; i < indexOfArray ; i++) {
        if(avlTree.getCount(numberInArray[i]) == 1) {
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

        usingAVLTree(line);
    }

    return 0;
}