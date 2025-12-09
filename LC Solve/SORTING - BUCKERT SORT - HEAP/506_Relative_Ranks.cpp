#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(N Log N) Sort
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[score[i]] = i;

        sort(score.begin(), score.end(), [&](int a, int b) {
            return a > b;
        });

        for(int i = 0; i < n; i++) {
            if(i == 0) ans[mp[score[i]]] = "Gold Medal";
            else if(i == 1) ans[mp[score[i]]] = "Silver Medal";
            else if(i == 2) ans[mp[score[i]]] = "Bronze Medal";
            else ans[mp[score[i]]] = to_string(i + 1);
        }

        return ans;
    }
};