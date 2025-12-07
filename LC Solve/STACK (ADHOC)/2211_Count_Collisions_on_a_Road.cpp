#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stackSolution(string d) {
        // LLRR
        int cnt = 0;
        vector<char> st;

        for (char c : d) {
            if (c == 'L') {
                if (!st.empty() && st.back() == 'R') {
                    cnt += 2; 
                    st.back() = 'S';
                    while (st.size() > 1 && st[st.size() - 2] == 'R') {
                        cnt++;
                        st.pop_back();
                        st.back() = 'S';
                    }
                } 

                else if (!st.empty() && st.back() == 'S') {
                    cnt += 1;
                } 

                else {
                    st.push_back('L');
                }
            } 
            else if (c == 'S') {
                while (!st.empty() && st.back() == 'R') {
                    cnt++;
                    st.pop_back();
                }
                st.push_back('S');
            } 
            else {
                st.push_back('R');
            }
        }
        
        return cnt;
    }

    int noStack(string d) {
        int n = d.length();

        // ELIMINASI 'L' DISEBELAH UJUNG KIRI, KRNA GAK AKAN PERNAH NABRAK
        int i = 0;
        while(i < n && d[i] == 'L') i++;

        // ELIMINIASI 'R' DISEBELAH UJUNG KANAN, KRNA GAK AKAN PERNAH NABRAK
        int j = n - 1;
        while(j >= 0 && d[j] == 'R') j--;

        int cnt = 0;
        for(i; i <= j; i++) {
            if(d[i] != 'S') cnt++;
        }

        return cnt;
    }

    int countCollisions(string d) {
        return noStack(d);
        return stackSolution(d);
    }
};
