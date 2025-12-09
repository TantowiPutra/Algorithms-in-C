#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char &c : s) mp[c]++;

        int maxFreq = INT_MIN, minFreq = INT_MAX;

        for(auto [ch, freq] : mp) {
            maxFreq = max(maxFreq, freq);
            minFreq = min(minFreq, freq);
        }

        vector<vector<char>> bucket(maxFreq - minFreq + 1);
        for(auto [ch, freq] : mp) {
            bucket[freq - minFreq].push_back(ch);
        }

        string res = "";
        for(int i = bucket.size() - 1; i >= 0; i--) {
            for(char ch : bucket[i]) {
                for(int j = 0; j < i + minFreq; j++) {
                    res.push_back(ch);
                }
            }
        }

        return res;
    }
};