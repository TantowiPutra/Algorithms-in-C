#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        for(auto a : t) tMap[a]++;

        int sLen = s.length(), tLen = t.length();
        int left = 0, right = 0;

        int leftIdx = 0, rightIdx = sLen - 1;
        bool found = false; 

        while(right < sLen) {
            if(tMap.find(s[right]) != tMap.end()) {
                if (tMap[s[right]] > 0) tLen--;
                tMap[s[right]]--;
            }

            while(tLen == 0 && left <= right) {
                if(rightIdx - leftIdx >= right - left) {
                    rightIdx = right;
                    leftIdx  = left;
                    found = true;
                }

                if(tMap.find(s[left]) != tMap.end()) {
                    tMap[s[left]]++;
                    if (tMap[s[left]] > 0) tLen++;
                }

                left++;
            }

            right++;
        }

        if (!found) return ""; 
        return s.substr(leftIdx, rightIdx - leftIdx + 1);
    }
};
