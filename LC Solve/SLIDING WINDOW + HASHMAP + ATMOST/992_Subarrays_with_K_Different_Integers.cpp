#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(freq[nums[i]] == 0) k--;
            freq[nums[i]]++;

            while(k < 0) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) k++;
                left++;
            }

            ans += (i - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};