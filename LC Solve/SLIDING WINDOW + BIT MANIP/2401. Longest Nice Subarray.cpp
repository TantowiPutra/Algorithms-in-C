#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1, used = 0, left = 0, n = nums.size();

        for(int right = 0; right < n; right++) {
            while((used & nums[right]) != 0) {
                used ^= nums[left];
                left++;
            }

            used |= nums[right];
            ans = max(right - left + 1, ans);
        }

        return ans;
    }
};