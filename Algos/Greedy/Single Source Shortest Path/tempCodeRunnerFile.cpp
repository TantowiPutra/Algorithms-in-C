#include <bits/stdc++.h>
using namespace std;

void woPq(vector<vector<pair<int, int>>> adj_list, int node, int n) {
    vector<bool> visited(n + 1, false);
    vector<int>  minCost(n + 1, INT_MAX);

    visited[node]   = true;
    minCost[node]   = 0;

    int pos         = node;

    for(int i = 1; i <= n; i++) {
        int currMinCost = INT_MAX;

        for(auto adj : adj_list[pos]) {
            int nd = get<0>(adj), w = get<1>(adj);

            minCost[nd] = min(minCost[nd], minCost[pos] + w);

            if(!visited[nd] && minCost[nd] < currMinCost) {
                pos         = nd;
                currMinCost = minCost[nd];
            }
        }

        if(currMinCost == INT_MAX) return;
        visited[pos] = true;

        for(auto adj : adj_list[pos]) {
            int nd = get<0>(adj), w = get<1>(adj);

            minCost[nd] = min(minCost[nd], minCost[pos] + w);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " " << minCost[i] << endl; 
    }
}

int main() {
    vector<vector<pair<int, int>>> adj_list = {
        {},
        {{ 2, 1 }, {3, 5}},
        {{ 1, 1 }, {3, 3}, {4, 10}, {5, 8}},
        {{ 1, 5 }, {2, 3}, {5, 2}},
        {{ 2, 10 }, {5, 8}, {6, 2}},
        {{ 2, 8 }, {3, 2}, {4, 3}, {6, 7}},
        {{ 4, 2 }, {5, 7}}
    };

    woPq(adj_list, 1, 6);

    return 0;
}