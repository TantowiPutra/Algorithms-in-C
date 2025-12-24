#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> empty;
    bool solve(
        vector<vector<char>>& board, 
        int idx,
        vector<vector<bool>> &rows, 
        vector<vector<bool>> &cols, 
        vector<vector<bool>> &subBox
    ) {
        if(idx >= empty.size()) 
            return true;

        auto [row, col] = empty[idx];
        int box  = ((row / 3) * 3) + (col / 3);

        for(int i = 1; i <= 9; i++) {
            bool isRow = rows[row][i];
            bool isCol = cols[col][i];
            bool isBox = subBox[box][i];

            if(isRow || isCol || isBox)
                continue;

            board[row][col] = (char) i + '0';
            rows[row][i] = cols[col][i] = subBox[box][i] = true;

            if(solve(board, idx + 1 ,rows, cols, subBox)) 
                return true;

            rows[row][i] = cols[col][i] = subBox[box][i] = false;
            board[row][col] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> subBox (9, vector<bool>(10, false));

        // ! MARKING
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int box = ((i / 3) * 3) + (j / 3);

                    subBox[box][num] = rows[i][num] = cols[j][num] = true;
                } else {
                    empty.push_back({ i, j });
                }
            }
        }

        solve(board, 0, rows, cols, subBox);
    }
};