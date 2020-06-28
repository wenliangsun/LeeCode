#include <bits/stdc++.h>

using namespace std;

/**
 * 题目37：解数独
 */

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) { dfs(board, 0, 0); }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        int n = 9, m = 9;
        if (y == m) return dfs(board, x + 1, 0);
        if (x == n) return true;
        if (board[x][y] != '.') return dfs(board, x, y + 1);
        for (char i = '1'; i <= '9'; i++) {
            if (isValid(board, x, y, i)) {
                board[x][y] = i;
                if (dfs(board, x, y + 1)) return true;
                board[x][y] = '.';
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int x, int y, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == c) return false;
            if (board[i][y] == c) return false;
            if (board[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] == c)
                return false;
        }
        return true;
    }
};