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

int main() {
    vector<vector<int>> adj_list(5);
    adj_list[0] = {1};
    adj_list[1] = {2};
    adj_list[2] = {3};
    adj_list[3] = {4};
    adj_list[4] = {};

    vector<bool> visited(5, false);
    stack<int> stk;
    
    for(int i = 0; i < 5; i++) {
        if(!visited[i])
            dfs(adj_list, i, visited, stk);
    }

    cout << "Topological Sort: ";
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }

    cout << endl;

    return 0;
}