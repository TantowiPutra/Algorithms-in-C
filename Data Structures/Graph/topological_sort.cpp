#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj_list, int node, vector<bool> &visited, stack<int> &stk) {
    visited[node] = true;

    for(int adj : adj_list[node]) {
        if(!visited[adj]) 
            dfs(adj_list, adj, visited, stk);
    }

    stk.push(node);
}

void dfs_topological(vector<vector<int>> adj_list) {
    vector<bool> visited(adj_list.size(), false);
    stack<int> stk;
    
    for(int i = 0; i < adj_list.size(); i++) {
        if(!visited[i])
            dfs(adj_list, i, visited, stk);
    }

    cout << "Topological Sort (DFS): ";
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    cout << endl;
}

void bfs_topological(vector<vector<int>> adj_list) {
    vector<int> indegree(adj_list.size());

    for(int i = 0; i < adj_list.size(); i++) {
        for(int adj : adj_list[i]) {
            indegree[adj]++; // O(V + E)
        }
    }

    queue<int> q;
    for(int i = 0; i < adj_list.size(); i++) { // O(V)
        if(indegree[i] == 0)
            q.push(i); 
    }

    cout << "Topological Sort (BFS): ";
    while(!q.empty()) { // O(V + E)
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int adj : adj_list[node]) {
            indegree[adj]--;
            if(indegree[adj] == 0)
                q.push(adj);
        }
    }
    cout << endl;

    return;
}

int main() {
    vector<vector<int>> adj_list(5);
    adj_list[0] = {1};
    adj_list[1] = {2};
    adj_list[2] = {3};
    adj_list[3] = {4};
    adj_list[4] = {};

    dfs_topological(adj_list);
    bfs_topological(adj_list);

    return 0;
}