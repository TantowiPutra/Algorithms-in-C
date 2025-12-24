#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &candidates, vector<int> &temp, int idx, int &sum, int target) {
        if(sum >= target) {
            if(sum == target) ans.push_back(temp);
            return;
        }

        if(idx >= candidates.size()) return;

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            sum += candidates[i];
            temp.push_back(candidates[i]);

            backtrack(candidates, temp, i + 1, sum, target);

            temp.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, temp, 0, sum, target);

        return ans;
    }
};