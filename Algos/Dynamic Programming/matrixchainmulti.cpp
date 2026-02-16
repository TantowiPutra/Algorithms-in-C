#include <bits/stdc++.h>
using namespace std;

int findMinCostRecurse(vector<int> &d, int l, int r) {
    if (r - l <= 1) {
        return 0;
    }

    int minCost = INT_MAX;

    for (int k = l + 1; k < r; k++) { // Do N process on each state, 
        int cost =
            findMinCostRecurse(d, l, k) +
            findMinCostRecurse(d, k, r) +
            d[l] * d[k] * d[r];

        minCost = min(minCost, cost);
    }

    return minCost;
}

int findMinCostMemo(vector<vector<int>> &dp, vector<int> &d, int l, int r) { // Overall (N^3) Time Complexity
    if (r - l <= 1) {
        return 0;
    }

    if(dp[l][r] != -1) return dp[l][r];

    int minCost = INT_MAX;

    for (int k = l + 1; k < r; k++) { // Do N process on each state, 
        int cost =
            findMinCostMemo(dp, d, l, k) +
            findMinCostMemo(dp, d, k, r) +
            d[l] * d[k] * d[r];

        minCost = min(minCost, cost);
    }

    return dp[l][r] = minCost;
}

int findMinCostIterative(vector<int> &d) {
    int n = d.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    /*
         0 1 2 3 
       0 0 
       1   0
       2     0
       3       0
    */

    for(int diff = 2; diff < n; diff++) {
        for(int i = 0; i <= n - diff - 1; i++) {
            int j = i + diff;
            dp[i][j] = INT_MAX;

            for(int k = i + 1; k < j; k++) {
                // 0 1 2 -> Matrix 1 and 2
                int cost = dp[i][k] + dp[k][j] + (d[i] * d[k] * d[j]);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> d = {3, 2, 4, 2, 5, 7};
    int n = d.size();

    vector<vector<int>> dp(n, vector<int>(n, -1)); // N ^ 2 State

    cout << "Min Cost Using Recursion  : " << findMinCostRecurse(d, 0, n - 1)  << endl;
    cout << "Min Cost Using Memoization: " << findMinCostMemo(dp, d, 0, n - 1) << endl;
    cout << "Min Cost Using Iteration  : " << findMinCostIterative(d) << endl;

    return 0;
}