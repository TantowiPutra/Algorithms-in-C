#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size(), left = 0;
        long long runningSum = 0, cnt = 0;

        for(int i = 0; i < n; i++) {
            runningSum += nums[i];

            while(runningSum * (i - left + 1) >= k) {
                runningSum -= nums[left++];
            }

            cnt += (i - left + 1);
        }

        return cnt;
    }
};