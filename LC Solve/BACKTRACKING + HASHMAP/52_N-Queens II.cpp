#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt = 0;
    void solve(int n, int row, vector<string> &board, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2) {
        if(row == n) {
            ++cnt;
            return;
        }

        for(int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + n;

            if(cols[col] || diag1[d1] || diag2[d2]) 
                continue; // udah ada di kolom / diagonal yang sama

            cols[col] = diag1[d1] = diag2[d2] = true;

            board[row][col] = 'Q';
            solve(n, row + 1, board, cols, diag1, diag2);
            board[row][col] = '.';

            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(n * 2 - 1, false);
        vector<bool> diag2(n * 2 - 1, false);
        vector<string> board(n, string(n, '.'));

        solve(n, 0, board, cols, diag1, diag2);

        return cnt;
    }
};