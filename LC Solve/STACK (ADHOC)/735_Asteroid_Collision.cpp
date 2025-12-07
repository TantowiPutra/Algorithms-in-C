#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        ans.push_back(asteroids[0]);

        for(int i = 1; i < n; i++) {
            if(asteroids[i] < 0) {
                while(ans.size() > 0 && ans.back() > 0 && ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }

                if(!ans.size() || ans.back() < 0) ans.push_back(asteroids[i]);
                else if(ans.size() && ans.back() == abs(asteroids[i])) ans.pop_back();
            } else {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};