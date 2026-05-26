#include <bits/stdc++.h>
using namespace std;

pair<int, int> setMethod(vector<pair<int, int>> &v, int maxWeight) { // O(2^N)
    vector<pair<int, int>> aux = {{ 0, 0 }};

    for(int i = 0; i < v.size(); i++) {
        int p = get<0>(v[i]), w = get<1>(v[i]);
        int sz = aux.size();

        for(int j = 0; j < sz; j++) {
            aux.push_back({ p + get<0>(aux[j]), w + get<1>(aux[j]) });
        }
    }

    int maxProfit = 0;
    int weight    = 0;

    for(int i = 0; i < aux.size(); i++) {
        if(get<0>(aux[i]) > maxProfit && get<1>(aux[i]) <= maxWeight) {
            maxProfit = get<0>(aux[i]);
            weight    = get<1>(aux[i]);
        }
    }


    return {maxProfit, weight};
}

int recursion(vector<pair<int, int>> &v, int n, int maxWeight) { // O(2^N)
    if(n == 0 || maxWeight <= 0) return 0;

    if(v[n - 1].second > maxWeight)
        return recursion(v, n - 1, maxWeight);

    int no  = recursion(v, n - 1, maxWeight); // Not Included
    int yes = recursion(v, n - 1, maxWeight - v[n - 1].second) + v[n - 1].first; // Included
    
    return max(no, yes);
}

int memoization(vector<vector<int>> &dp, vector<pair<int, int>> &v, int n, int maxWeight) {
    if(n == 0 || maxWeight <= 0) return 0;
    if(dp[n][maxWeight] != -1) return dp[n][maxWeight];

    if(v[n].second > maxWeight)
        return dp[n][maxWeight] = memoization(dp, v, n - 1, maxWeight); // Keep it as it is

    int no  = memoization(dp, v, n - 1, maxWeight);
    int yes = memoization(dp, v, n - 1, maxWeight - v[n].second) + v[n].first; 

    return dp[n][maxWeight] = max(no, yes);
}

int tabulation(vector<pair<int, int>> &v, int maxWeight) {
    int m = v.size() + 1, n = maxWeight + 1;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 1; i < m; i++) {
        for(int j = 1; j <= maxWeight; j++) {
            if(j >= v[i - 1].second) 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].second] + v[i - 1].first);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j <= maxWeight; j++) {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    return dp[m - 1][n - 1];
}

int main() {
    int maxWeight = 8;
    vector<pair<int, int>> v = { // P (Profit), W (Weight)
        {1, 2},
        {2, 3},
        {5, 4},
        {6, 5}    
    };
    
    pair<int, int> setRes = setMethod(v, maxWeight);
    cout << "0 /1 KnapSack Using Set Method: " << setRes.first << ", Weight: " << setRes.second << endl;

    int recursionRes = recursion(v, v.size(), maxWeight);
    cout << "0 /1 KnapSack Using Recursion: " << recursionRes << endl;

    vector<vector<int>> dp(4, vector<int>(maxWeight + 1, -1));
    int memoizationRes = memoization(dp, v, v.size() - 1, maxWeight);
    cout << "0 / 1 KnapSack Using Memoization: " << memoizationRes << endl;

    cout << "0 / 1 KnapSack Using Tabulation: " << tabulation(v, 8) << endl;

    return 0;
}