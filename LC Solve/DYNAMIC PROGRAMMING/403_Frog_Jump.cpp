#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        unordered_map<long long, bool> memo;

        function<bool(int,int)> dfs = [&](int pos, int lastJump) {
            if (pos == n - 1) return true;

            long long key = ((long long)pos << 32) | (unsigned)lastJump; // BIT DP
            if (memo.count(key)) return memo[key];

            for (int i = pos + 1; i < n; ++i) {
                int dis = stones[i] - stones[pos];
                if (dis < lastJump - 1) continue;
                if (dis > lastJump + 1) break;

                if (dfs(i, dis)) return memo[key] = true;
            }

            return memo[key] = false;
        };

        return dfs(1, 1);
    }
};
