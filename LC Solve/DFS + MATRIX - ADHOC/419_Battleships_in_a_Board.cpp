#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS O(N * M)
    int withModif(vector<vector<char>> &board) {
        int cnt = 0, n = board.size(), m = board[0].size();
        int dir[4][2] = {{ -1, 0 }, {1, 0}, {0, -1}, {0, 1}};
        stack<pair<int, int>> stk;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'X') {
                    cnt++;
                    stk.push({ i , j });

                    while(!stk.empty()) {
                        auto [x, y] = stk.top(); stk.pop();
                        for(int k = 0; k < 4; k++) {
                            int movX = x + dir[k][0];
                            int movY = y + dir[k][1];

                            if(movX >= 0 && movX < n && movY >= 0 && movY < m && board[movX][movY] == 'X') {
                                board[movX][movY] = '.';
                                stk.push({ movX, movY });
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }

    // O(N * M) -> Ad Hoc Trick
    int withoutModif(vector<vector<char>> &board) {
        int cnt = 0, n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'X') {
                    if (board[i][j] != 'X') continue;

                    // CHECK KIRI DAN ATAS
                    if (i > 0 && board[i-1][j] == 'X') continue;
                    if (j > 0 && board[i][j-1] == 'X') continue;

                    cnt++;
                }
            }
        }

        return cnt;
    }

    int countBattleships(vector<vector<char>>& board) {
        return withoutModif(board);
        return withModif(board);
    }
};