#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, runningSum = 0, maxSum = INT_MIN;
        unordered_set<int> set;

        for(int i = 0; i < n; i++) {
            runningSum += nums[i];

            while(left < i && set.count(nums[i])) {
                runningSum -= nums[left];
                set.erase(nums[left]);
                left++; 
            }

            set.insert(nums[i]);
            maxSum = max(maxSum, runningSum);
        }
        
        return maxSum;
    }
};