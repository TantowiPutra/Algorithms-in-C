#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<Node *, Node*> m;
    Node* dfs(Node *node) {
        if(!node) return nullptr;
        if(m.find(node) != m.end()) return m[node];

        int n = node->neighbors.size();
        vector<Node *> newNeightbors(n, nullptr);
        Node *newNode = new Node(node->val, newNeightbors);

        m[node] = newNode;

        for(int i = 0; i < n; i++) {
            newNode->neighbors[i] = dfs(node->neighbors[i]);            
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};