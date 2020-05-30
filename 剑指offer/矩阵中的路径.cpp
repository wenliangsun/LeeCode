#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size()) return false;
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    /**
     * 二维回溯法
     */
    bool dfs(vector<vector<char>>& board, int x, int y, string& w, int idx) {
        if (board[x][y] != w[idx]) return false;
        if (idx == w.size() - 1) return true;
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                if (dfs(board, a, b, w, idx + 1)) return true;
            }
        }
        board[x][y] = w[idx];
        return false;
    }
};