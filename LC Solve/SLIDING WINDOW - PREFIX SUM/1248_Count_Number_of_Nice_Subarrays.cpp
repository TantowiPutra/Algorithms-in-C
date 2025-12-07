#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingWindow(vector<int> &nums, int k) {
        int totalOdd = 0, left = 0, cnt = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) totalOdd++;

            while(left <= i && totalOdd > k) {
                if(nums[left] % 2 == 1) totalOdd--;
                left++;
            }

            int lCpy   = left;
            int oddCpy = totalOdd;

            while(lCpy <= i && oddCpy == k) {
                if(nums[lCpy] % 2 == 1) oddCpy--;
                lCpy++;
                cnt++;
            }
        }

        return cnt;
    }

    int prefixSum(vector<int> &nums, int k) {
        /*
            [2,2,2,1,2,2,1,2,2,2]
            i = 6, cnt = 4;
            i = 7, cnt = 8;
            i = 8, cnt = 12;
            i = 9, cnt = 16;
        */

        int n = nums.size(), cnt = 0;
        unordered_map<int, int> map;

        map[0]++;
        int prefixCount = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) prefixCount++;

            if(map.find(prefixCount - k) != map.end()) {
                cnt += map[prefixCount - k];
            }

            map[prefixCount]++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return prefixSum(nums, k);
        return slidingWindow(nums, k);
    }
};