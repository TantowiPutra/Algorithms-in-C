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
    stack<int> s;

    // STARTING FROM 1
    s.push(1);
    visited.insert(1);

    while(!s.empty()) {
        int front = s.top(); s.pop();

        for(int node : adj_list[front]) {
            if(!visited.count(node)) {
                visited.insert(node);
                s.push(node);
            }
        }

        cout << front << " ";
    }

    return 0;
}