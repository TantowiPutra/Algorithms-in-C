#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<unordered_set<int>> adj_list = {
        {},
        {2, 3, 4},
        {1, 3},
        {1, 2, 4, 5},
        {1, 5},
        {3, 4, 6, 7},
        {5},
        {5}
    };

    unordered_set<int> visited;
    queue<int> q;

    // STARTING FROM 1
    q.push(1);
    visited.insert(1);

    while(!q.empty()) {
        int front = q.front(); q.pop();

        for(int node : adj_list[front]) {
            if(!visited.count(node)) {
                visited.insert(node);
                q.push(node);
            }
        }

        cout << front << " ";
    }

    return 0;
}