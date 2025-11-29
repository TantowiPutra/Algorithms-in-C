#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*
            P     I    N
            A   L S  I G
            Y A   H R
            P     I

            numRows = R = 4

            1 Cycle Penuh:
            Step 0: P

            Step 1: A
            Step 2: Y
            Step 3: P
            Step 4: A
            Step 5: L
            Step 6: I
            Disini ada 6 step untuk geser dari satu titik awal ke titik awal lainnya, dalam baris yang sama
            Jadi bisa disimpulkan Rumusnya 1x cycle tuh *** c = numRows * 2 - 2 ***
        */

        if(numRows == 1) return s; 
        int n = s.size();

        int cyc = numRows * 2 - 2;
        string ans;
        ans.reserve(n);

        for(int r = 0; r < numRows; r++) {
            for(int c = r; c < n; c += cyc) {
                ans += s[c];

                int diag = c + cyc - 2 * r;
                if (r != 0 && r != numRows - 1 && diag < n) {
                    ans += s[diag];
                }
            }
        }

        return ans;
    }
};