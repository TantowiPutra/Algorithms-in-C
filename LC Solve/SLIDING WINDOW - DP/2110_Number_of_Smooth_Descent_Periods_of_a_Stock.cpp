#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int left = 0, right = 0;
        long long cnt = 0;

        for(right = 0; right < n; right++) {
            if(right > 0 && prices[right - 1] - prices[right] != 1) {
                left = right;
            }
            
            cnt += (right - left) + 1;
        }

        return cnt;
    }
};