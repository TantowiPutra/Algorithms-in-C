#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS TOPOLOGICAL SORT
        vector<vector<int>> adj_list(numCourses);
        vector<int> indegree(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            int to_take = prerequisites[i][0], mandatory = prerequisites[i][1];
            adj_list[mandatory].push_back(to_take);

            indegree[to_take]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            cnt++;

            for(int adj : adj_list[node]) {
                if(--indegree[adj] == 0)
                    q.push(adj);
            }
        }

        if(cnt < numCourses)
            return {};

        return ans;
    }
};