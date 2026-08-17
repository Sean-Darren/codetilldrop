#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;


set<int> bfsFindCity(int start, vector<vector<int>>& graph, int num){
    set<int> canBeChosen;
    vector<bool> isVisited(num+1, false);

    queue<int> que;
    
    que.push(start);
    isVisited[start] = true;
    canBeChosen.insert(start);

    while(que.size() != 0) {
        int cityNum = que.front();
        que.pop();

        for(int city: graph[cityNum]){
            if(isVisited[city] == false) {
                isVisited[city] = true;
                canBeChosen.insert(city);
                que.push(city);
            }
        }
    }

    return canBeChosen;
}

set<int> setIntersection(const set<int>& first, const set<int>& second) {
    set<int> theResult;
    set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(theResult, theResult.begin()));

    return theResult;
}

int main() {
    int K;
    cin >> K;

    int N;
    cin >> N;
    
    int M;
    cin >> M;

    vector<int> kFriends(K);

    for(int i = 0 ; i < K ; i++) {
        cin >> kFriends[i];
    }

    vector<vector<int>> adjacencyList(N+1);

    for(int i = 0 ; i < M ; i++) {
        int a;
        cin >> a;
        int b;
        cin >> b;

        adjacencyList[a].push_back(b);
    }

    set<int> findCity = bfsFindCity(kFriends[0], adjacencyList, N);

    for(int i = 1 ; i < K ; i++) {
        set<int> chosenCity = bfsFindCity(kFriends[i], adjacencyList, N);
        findCity = setIntersection(findCity, chosenCity);
    }

    cout << findCity.size() << endl;

    return 0;
}