#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for(const int x : s) {
            if(!s.count(x - 1)) {
                int len = 1;
                int curNum = x;

                while(s.count(curNum + 1)) {
                    len++;
                    curNum++;
                }

                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};