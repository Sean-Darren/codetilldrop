#include <iostream>
#include <vector>
using namespace std;

int wAudiences[5001];
vector<int> listOfCitiesConnected[5001];
int theDistance[5001];
bool isVisited[5001];

void dfs(int current, int parent, int d) {
    theDistance[current] = d;
    isVisited[current] = true;

    int neighbor;
    for(int i = 0 ; i < listOfCitiesConnected[current].size() ; i++) {
        neighbor = listOfCitiesConnected[current][i];
        
        if(neighbor != parent) {
            dfs(neighbor, current, d + 1);
        }
    }
}

long long calculateCost(int concertC, int n) {
    for(int i = 1; i <= n ; i++) {
        theDistance[i] = 0;
        isVisited[i] = false; 
    }

    dfs(concertC, -1, 0);

    long long total = 0;

    for(int i = 1; i <= n ; i++) {
        total += theDistance[i] * wAudiences[i];
    }

    return total;
}

int main() {

    int numberOfCities;
    cin >> numberOfCities;

    for(int i = 1; i < numberOfCities + 1; i++) {
        int w, l, r;
        cin >> w >> l >> r;

        wAudiences[i] = w;

        if( l != 0 ) {
            listOfCitiesConnected[i].push_back(l);
            listOfCitiesConnected[l].push_back(i);
        }

        if( r != 0 ) {
            listOfCitiesConnected[i].push_back(r);
            listOfCitiesConnected[r].push_back(i);
        }
    }

    long long minimalCost = 1e18;

    for(int i = 1; i <= numberOfCities ; i++) {
        long long cost = calculateCost(i,numberOfCities);

        if(cost < minimalCost) {
            minimalCost = cost;
        }
    }

    cout << minimalCost << endl;

    return 0;
}