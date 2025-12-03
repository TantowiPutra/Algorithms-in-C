#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingWindow(vector<int> &nums, int goal) {
        /*
            Kondisi Shrink Subarray:
            windowSum > goal
        */ 

        int l = 0, n = nums.size(), cnt = 0, windowSum = 0;
        for(int i = 0; i < n; i++) {
            windowSum += nums[i];

            while(l <= i && windowSum > goal) {
                windowSum -= nums[l++];
            }

            // Coba shrink dari posisi sekarang semisal == goal, cover semua subarray
            int lCpy         = l;
            int windowSumCpy = windowSum;

            while(lCpy <= i && windowSumCpy == goal) {
                windowSumCpy -= nums[lCpy];
                cnt++;
                lCpy++;
            }
        }

        return cnt;
    }

    int prefixSum(vector<int> &nums, int goal) {
        int l = 0, n = nums.size(), prefixSum = 0, cnt = 0;
        unordered_map<int, int> map;
        map[0] = 1;

        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];
            if(map.find(prefixSum - goal) != map.end()) {
                cnt += map[prefixSum - goal];
            }
            
            map[prefixSum]++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {\
        return prefixSum(nums, goal);
        return slidingWindow(nums, goal);
    }
};