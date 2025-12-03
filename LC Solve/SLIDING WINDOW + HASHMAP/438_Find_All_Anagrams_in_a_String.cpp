#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /*
            Intuition:
            - Anagrams requires frequency, therefore, it's mandatory to map frequencies of p
            - shrink window condition: when frequency of existing character drops to zero, or 
              the current character does not exist in the list

              Overall, the time complexity will be O(N), and space complexity is O(1) since we will
              only need to map 26 lowercase english characters.

              At least that's what i think the best approach would be...
        */

        int freqMap[26] = {0};
        for(char a  : p) freqMap[a - 'a']++;
        for(int  &x : freqMap) if(x == 0) x = 1e5;

        int left = 0, lenP = p.length();
        vector<int> ans;
        for(int i = 0; i < s.length(); i++) {
            // Skip Window ini kalo karakter invalid
            if(freqMap[s[i] - 'a'] == 1e5) {
                while(left < i) {
                    freqMap[s[left] - 'a']++;
                    lenP++;
                    left++;
                }

                left++;
                continue;
            }

            // Character Valid
            freqMap[s[i] - 'a']--;
            if(freqMap[s[i] - 'a'] >= 0) lenP--;

            while(freqMap[s[i] - 'a'] < 0) {
                freqMap[s[left] - 'a']++;
                if(freqMap[s[left] - 'a'] > 0) lenP++;
                left++;
            }

            if(lenP == 0) ans.push_back(left);
        }

        return ans;
    }
};