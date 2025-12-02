#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N!) -> TLE
    int backTrackingWithoutPrunning(vector<int> &perm, int idx) {
        if (idx == perm.size()) {
            bool isB = true;

            for(int i = 0; i < perm.size();i++) {
                if(perm[i] % (i + 1) != 0 && (i + 1) % perm[i] != 0) {
                    isB = false;
                    break;
                }
            }

            return isB ? 1 : 0;
        }

        int ans = 0;
        for (int i = idx; i < perm.size(); i++) {
            swap(perm[idx], perm[i]);
            ans += backTrackingWithoutPrunning(perm, idx + 1);
            swap(perm[idx], perm[i]);
        }

        return ans;
    }

    // O(N!) -> ACCEPTED
    int backTrackingWithPrunning(vector<int> &perm, int idx) {
        if (idx == perm.size()) return 1;

        int ans = 0;
        for (int i = idx; i < perm.size(); i++) {
            swap(perm[idx], perm[i]);
            
            if(perm[idx] % (idx + 1) == 0 || (idx + 1) % perm[idx] == 0) 
                ans += backTrackingWithPrunning(perm, idx + 1);

            swap(perm[idx], perm[i]);
        }

        return ans;
    }


    int countArrangement(int n) {
        /*
            N = 3;
            1 2 3 YES
            1 3 2 NO
            2 1 3 YES
            2 3 1 NO
            3 1 2 NO
            3 2 1 YES

            OUTPUT = 3
        */

        vector<int> perm;
        perm.resize(n);
        for(int i = 1; i <= n; i++) perm[i - 1] = i;

        return backTrackingWithPrunning(perm, 0);
    }
};