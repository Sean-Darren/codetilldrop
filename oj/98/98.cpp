#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visitedList[505];
vector<int> adjacencyList[505];
bool inCurrentComponent[505]; 
int vertexCountNum, edgeCountNum;


void dfs(int node) {
    visitedList[node] = true;
    inCurrentComponent[node] = true;
    vertexCountNum = vertexCountNum + 1;

    for(int i = 0 ; i < adjacencyList[node].size() ; i++){
        int neighbor = adjacencyList[node][i];

        if (!visitedList[neighbor]) {
            dfs(neighbor);
        }
    }

}

int main() {
    int n;
    int m;

    int caseNumber = 1;

    while(cin >> n >> m) {
        if (n == 0 && m ==0) {
            break;
        }

        for(int i = 1 ; i <= 505 ; i++){
            adjacencyList[i].clear();
        }
        memset(visitedList, false, sizeof(visitedList));

        for(int i = 0 ; i < m ; i++) {
            int firstNum, secNum;

            cin >> firstNum >> secNum;

            adjacencyList[firstNum].push_back(secNum);
            adjacencyList[secNum].push_back(firstNum);

        }

        int treeCount = 0;

        for(int i = 1 ; i <=n ; i++) {
            if(visitedList[i] == false) {
                vertexCountNum = 0;
                edgeCountNum = 0;

                memset(inCurrentComponent, false, sizeof(inCurrentComponent)); 

                dfs(i);

                for(int j = 1; j <= n ; j++) {
                    if(inCurrentComponent[j]) 
                        edgeCountNum += adjacencyList[j].size();
                }

                edgeCountNum /= 2;

                if(edgeCountNum == vertexCountNum - 1) { 
                    treeCount++;
                }
            }
        }

        cout << "Case " << caseNumber << ": ";

        caseNumber++;

        if(treeCount == 0) {
            cout << "No trees." << endl;
        } else if (treeCount == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout << "A forest of " << treeCount << " trees." << endl;
        }
    }


    return 0;
}