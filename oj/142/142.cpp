#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
    private:
        vector<int> parentNode;
        vector<int> size;
        int maximum;

    public:
        UnionFind(int number) {
            parentNode.resize(number+1);
            size.resize(number+1);
            maximum = 1;

            for(int i = 1 ; i <= number ; i++) {
                parentNode[i] = i;
                size[i] = 1;
            }
        }

        int findRoot(int x) {
            if(parentNode[x] != x) {
                parentNode[x] = findRoot(parentNode[x]);
            }

            return parentNode[x];
        }

        int getMaximumSize() { return maximum; }

        void mergeUnionComponents(int first, int second) {
            int firstRoot = findRoot(first);
            int secondRoot = findRoot(second);


            if(firstRoot == secondRoot) { return; }

            if(size[firstRoot] < size[secondRoot]) {
                parentNode[firstRoot] = secondRoot;
                size[secondRoot] += size[firstRoot];
                maximum = max(maximum, size[secondRoot]);
            } else {
                parentNode[secondRoot] = firstRoot;
                size[firstRoot] +=   size[secondRoot];
                maximum = max(maximum, size[firstRoot]);
            }
        }
};

int main() {
    int numOfTC;
    cin >> numOfTC;

    while(numOfTC--) {
        int n, m;
        int a, b;
        cin >> n >> m;

        UnionFind unionFind(n);

        for(int i = 0 ; i < m ; i++){
            cin >> a >> b;
            unionFind.mergeUnionComponents(a,b);
        }
        cout << unionFind.getMaximumSize() << endl;
    }
    return 0;
}