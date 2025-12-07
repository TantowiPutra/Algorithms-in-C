#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), prefix = nums[0], left = 0, cnt = 0;
        if(nums[0] < k) cnt++;

        for(int i = 1; i < n; i++) {
            prefix *= nums[i];

            while(left <= i && prefix >= k) {
                prefix /= nums[left];
                left++;
            }

            cnt += (i - left + 1);
        }

        return cnt;
    }
};