#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[105];
int parent[105];
int depth[105];

void dfsMethod(int node, int parentP, int depthP) {
    parent[node] = parentP;
    depth[node] = depthP;

    int theChild = 0;
    for(int i = 0 ; i < tree[node].size() ; i++){
        theChild = tree[node][i];
        dfsMethod(theChild, node, depthP + 1);
    }
}

int findLowestCommonAncestors(int first, int second){
    while(depth[first] > depth[second]) {
        first = parent[first];
    }

    while(depth[first] < depth[second]) {
        second = parent[second];
    }

    while(first != second) {
        first = parent[first];
        second = parent[second];
    }

    return first;
}

int main() {
    int test;
    cin >> test;

    while(test--){
        int root;
        int number;
        cin >> root >> number;

        for(int i = 1; i < number + 1 ; i++){
            tree[i].clear();
            parent[i] =-1;
        }

        int child, par;
        for(int i = 0 ; i < number -1 ;i++) {
            cin >> child;
            cin >> par;

            tree[par].push_back(child);
        }

        dfsMethod(root, root, 0);

        int first, second;
        cin >> first >> second;

        cout << findLowestCommonAncestors(first, second) << endl;
    }

    return 0;
}