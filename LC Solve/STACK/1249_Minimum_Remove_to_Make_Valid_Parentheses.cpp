#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stackApproach(string s) {
        int n = s.length();
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i);
            } else if(s[i] == ')') {
                if(!stk.empty()) stk.pop();
                else s[i] = '*';
            }
        }

        while(!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }

    string withoutStack(string s) {
        int n = s.length();
        
        int openCnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') openCnt++;

            else if(s[i] == ')') {
                if(openCnt <= 0) {
                    s[i] = '*';
                } else {
                    openCnt--;
                }
            }
        }
        
        int closeCnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')') closeCnt++;

            else if(s[i] == '(') {
                if(closeCnt <= 0) {
                    s[i] = '*';
                } else {
                    closeCnt--;
                }
            }
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }

    string minRemoveToMakeValid(string s) {
        return withoutStack(s);
        return stackApproach(s);
    }
};
