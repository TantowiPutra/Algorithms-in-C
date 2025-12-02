#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length() < 3) return false;

        int cnt = 0;
        for(int i = 2; i < s.length(); i++) {
            if(s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) 
                cnt++;
        }

        return cnt;
    }
};

