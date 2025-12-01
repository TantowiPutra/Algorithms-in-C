#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
    
        int firstPos = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] < target) {
                l = mid + 1;
            } else if(nums[mid] >= target) {
                if(nums[mid] == target) firstPos = mid;
                r = mid - 1;
            } 
        }

        l = 0, r = n - 1;

        int secondPos = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] <= target) {
                if(nums[mid] == target) secondPos = mid;
                l = mid + 1;
            } else if(nums[mid] > target) {
                r = mid - 1;
            }
        }

        return {firstPos, secondPos};
    }
};