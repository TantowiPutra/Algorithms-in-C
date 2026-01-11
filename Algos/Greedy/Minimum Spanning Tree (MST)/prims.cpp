#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> adj_mat, int n) {
    int minCost = 0;
    vector<int> near(n + 1, INT_MAX);
    vector<bool> selected(n + 1, false);
    
    // ! LOOK FOR LOWEST COST NEAREST NODE
    int u = 1, v, min = INT_MAX;
    for(int i = 1; i <= n; i++) {
        if(adj_mat[u][i] < min) {
            v = i;
            min = adj_mat[u][i];
        }
    }

    // ! UPDATE NEAR TABLE
    selected[u] = selected[v] = true;
    minCost    += adj_mat[u][v]; 

    for(int i = 1; i <= n; i++) {
        if(adj_mat[u][i] < adj_mat[v][i])
            near[i] = u;
        else 
            near[i] = v;
    }

    for(int i = 1; i <= n - 2; i++) { // ! 2 ALREADY SELECTED INITIALLY
        int min = INT_MAX;

        // ! SELECT NEXT MINIMUM EDGE
        for(int j = 1; j <= n; j++) {
            if(!selected[j] && adj_mat[j][near[j]] < min) {
                min = adj_mat[j][near[j]];
                v   = j;
            }
        }

        // ! UPDATE NEAR TABLE
        u = near[v], minCost += min, selected[v] = true;
        for(int k = 1; k <= n; k++) {
            if(!selected[k] && adj_mat[k][v] < adj_mat[k][near[k]]) {
                near[k] = v;
            }
        }
    }
    
    return minCost;
}

int main() {
    vector<vector<int>> adj_mat = {
        {},
        {INT_MAX, INT_MAX, 28, INT_MAX, INT_MAX, INT_MAX, 10, INT_MAX},
        {INT_MAX, 28, INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 14},
        {INT_MAX, INT_MAX, 16, INT_MAX, 12, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 12, INT_MAX, 22, INT_MAX, 18},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 22, INT_MAX, 25, 24},
        {INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX, 25, INT_MAX, INT_MAX},
        {INT_MAX,INT_MAX, 14, INT_MAX, 18, 24, INT_MAX, INT_MAX}
    };
    int n = 7;
    cout << "Minimum Cost Spanning Tree: " << solve(adj_mat, n) << endl;

    return 0;
}