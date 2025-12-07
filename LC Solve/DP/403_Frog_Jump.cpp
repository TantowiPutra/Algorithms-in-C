#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool topDownDP(vector<int> &stones) {
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

    bool bottomUpDP(vector<int> &stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]];
        }
        mp[0].insert(0);

        for(int stone : stones) {
            for(int jump : mp[stone]) {
                for(int distance : {jump - 1, jump, jump + 1}) {
                    if(mp.find(stone + distance) != mp.end()) {
                        mp[stone + distance].insert(distance);
                    }
                }
            }
        }

        return !mp[stones.back()].empty();
    }

    bool canCross(vector<int>& stones) {
        return bottomUpDP(stones);

        return topDownDP(stones);
    }
};

