#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;

        int cnt = 0;
        int prefix = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int target = prefix - k;
            if(map.find(target) != map.end()) {
                cnt += map[target];
            }

            map[prefix]++;
        }

        return cnt;
    }
};