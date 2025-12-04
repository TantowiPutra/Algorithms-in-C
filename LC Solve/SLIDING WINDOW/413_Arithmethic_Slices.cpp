#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        /*
            Keep growing window when size < 3
        */

        int cnt = 0, left = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i - left + 1 < 3) continue;

            if(nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2]) {
                left = i - 1;
                continue;
            }

            cnt += i - left - 1;
        }   

        return cnt;
    }
};