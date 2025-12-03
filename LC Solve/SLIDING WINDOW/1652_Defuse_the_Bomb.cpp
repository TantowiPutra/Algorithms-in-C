#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) return res;

        if(k > 0) {
            int windowSum = 0;
            for(int i = 1; i <= k; i++) {
                windowSum += code[i];
            }

            res[0] = windowSum;
            for(int i = 1; i < n; i++) {
                windowSum += code[(i + k) % n] - code[i];
                res[i] = windowSum;
            }
        }

        if(k < 0) {
            int windowSum = 0;
            for(int i = n + k; i < n; i++) {
                windowSum += code[i];
            }

            res[0] = windowSum;
            for(int i = 1; i < n; i++) {
                windowSum += code[i - 1] - code[(i - 1 + k + n) % n];
                res[i] = windowSum;
            }
        }

        return res;
    }
};