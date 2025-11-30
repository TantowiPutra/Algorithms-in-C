#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int optimized(vector<int> &nums, int p) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int r = total % p;

        if(r == 0) return 0;

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1;

        int  ans = n;
        long long prefixSum = 0;

        for(int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;

            int target = (prefixSum - r + p) % p;

            if(lastIndex.count(target)) {
                ans = min(ans, i - lastIndex[target]);
            }

            lastIndex[prefixSum] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }

    int minSubarray(vector<int>& nums, int p) {
        return optimized(nums, p);
    }
};

