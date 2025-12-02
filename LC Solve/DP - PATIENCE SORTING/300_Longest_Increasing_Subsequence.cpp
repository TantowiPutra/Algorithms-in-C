#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N^2)
    int bottomUpDP(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLen = 1;
        for(int x : dp) maxLen = max(maxLen, x);

        return maxLen;
    }

    // O(N^2)
    int topDownDP(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int pos) {
            if(dp[pos] != -1) return dp[pos];

            int best = 1;
            for(int i = pos + 1; i < n; i++) {
                if(nums[pos] < nums[i]) {
                    best = max(best, 1 + dfs(i));
                }
            }

            return dp[pos] = best;
        };

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }

        return ans;
    }
    
    // O(N Log N)
    int patienceSorting(vector<int>& nums) {
        vector<int> tails;  

        for (int x : nums) {
            int l = 0, r = tails.size();

            while (l < r) {
                int mid = (l + r) / 2;
                if (tails[mid] < x)
                    l = mid + 1;
                else
                    r = mid;
            }

            if (l == tails.size())
                tails.push_back(x);   
            else
                tails[l] = x;         
        }

        return tails.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        return patienceSorting(nums);
        return topDownDP(nums);
        return bottomUpDP(nums);
    }
};
