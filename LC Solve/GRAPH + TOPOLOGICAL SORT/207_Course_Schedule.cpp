#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> state;

    bool dfs(int course) {
        if(state[course] == 2) return true;
        if(state[course] == 1) return false;

        state[course] = 1;
        for(auto prereq : adj[course]) {
            if(!dfs(prereq))
                return false;
        }
        state[course] = 2;

        return true;
    }

    bool DFS3Way(int numCourses, vector<vector<int>> &prerequisites) {
        adj.resize(numCourses);
        state.assign(numCourses, 0); // Set Unvisited

        int n = prerequisites.size();
        for(int i = 0; i < n; i++) {
            int course_to_take      = prerequisites[i][0];
            int prerequisite_course = prerequisites[i][1];

            adj[course_to_take].push_back(prerequisite_course);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i))
                return false;
        }

        return true;
    }

    // 3 - WAY DFS (0 : Unvisited, 1: Visiting, 2: Done)
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        return DFS3Way(numCourses, prerequisites);
    }

    // GABISA KARENA SETIAP COURSE BISA JADI KOMPONEN TERPISAH :(
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     int n = prerequisites.size();
    //     // vector<int> isTaken(numCourses, false);
    //     vector<int> visited(numCourses, false);

    //     vector<unordered_set<int>> adj_mat(numCourses);
    //     for(int i = 0; i < n; i++) {
    //         int course_to_take   = prerequisites[i][0];
    //         int must_take_course = prerequisites[i][1];

    //         // cout << course_to_take << " " << must_take_course << endl; 

    //         adj_mat[course_to_take].insert(must_take_course); 
    //     } 

    //     for(int i = 0; i < numCourses; i++) {
    //         cout << i << ": ";
    //         for(auto course : adj_mat[i]) {
    //             cout << course << " ";
    //         }

    //         cout << endl;        
    //     } 

    //     queue<int> q;
    //     q.push(0); // Mulai dari course 0;
    //     while(!q.empty()) {
    //         int front = q.front(); q.pop();
    //         if(visited[front]) return false;

    //         visited[front] = true;
    //         for(int course : adj_mat[front]) {
    //             if(course == front) return false;

    //             q.push(course);
    //         }
    //     }

    //     return true;
    // }
};