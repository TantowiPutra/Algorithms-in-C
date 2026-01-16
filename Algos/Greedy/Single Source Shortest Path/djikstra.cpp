#include <bits/stdc++.h>
using namespace std;

// O (N^3) -> Djikstra w/o PQ, path copy
void woPq(vector<vector<pair<int, int>>> adj_list, int node, int n) {
    vector<bool>                   visited(n + 1, false);
    vector<pair<int, vector<int>>> minCost(n + 1, {INT_MAX, {}});

    minCost[node]   = {0, {node}};
    int pos         = node;

    for(int i = 1; i <= n; i++) {
        int currMinCost = INT_MAX;

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && minCost[j].first < currMinCost) {
                currMinCost = minCost[j].first;
                pos         = j;
            }
        }

        if(currMinCost == INT_MAX) break;
        visited[pos] = true;

        for(auto adj : adj_list[pos]) {
            int nd = get<0>(adj), w = get<1>(adj);

            if(!visited[nd] && minCost[nd].first > currMinCost + w) {
                minCost[nd].first  = currMinCost + w;
                minCost[nd].second = minCost[pos].second;
                minCost[nd].second.push_back(nd); 
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " " << minCost[i].first << " || ";

        for(auto path : minCost[i].second) {
            cout << path << " ";
        }

        cout << endl;
    }
}

void getPath(vector<int> &parent, int node) {
    if(parent[node] == -1) {
        cout << node << " ";
        return;
    }

    getPath(parent, parent[node]);
    cout << node << " ";
}
// O(V^2) -> Using Parent Array
void woPq2(vector<vector<pair<int, int>>> adj_list, int node, int n) {
    vector<bool> visited(n + 1, false);
    vector<int>  dist(n + 1, INT_MAX);
    vector<int>  parent(n + 1, -1);

    dist[node] = 0;

    for(int i = 1; i <= n; i++) {
        int pos     = -1;
        int minCost = INT_MAX;

        for(int j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < minCost) {
                pos = j;
                minCost = dist[j];
            }
        }

        if(pos == -1) break;
        visited[pos] = true;

        for(auto adj : adj_list[pos]) {
            if(!visited[adj.first] && dist[adj.first] > minCost + adj.second) {
                dist[adj.first]   = minCost + adj.second;
                parent[adj.first] =  pos;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << " || ";
        getPath(parent, i);
        cout << endl;
    }
}

void wPq(vector<vector<pair<int, int>>> adj_list, int node, int n) {
    vector<bool> visited(n + 1, false);
    vector<int>  dist(n + 1, INT_MAX);
    vector<int>  parent(n + 1, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[node] = 0;
    pq.push({ 0, node });

    while(!pq.empty()) {
        pair<int, int> top = pq.top(); pq.pop();
        int w  = top.first;
        int nd = top.second;
        
        if(visited[nd]) continue;
        visited[nd] = true;

        for(auto adj : adj_list[nd]) {
            if(!visited[adj.first] && dist[adj.first] > w + adj.second) {
                dist[adj.first]   = w + adj.second;
                parent[adj.first] = nd;
                pq.push({ w + adj.second, adj.first });
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << " || ";
        getPath(parent, i);
        cout << endl;
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
    woPq2(adj_list, 1, 6);
    wPq(adj_list, 1, 6);

    return 0;
}