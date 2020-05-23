#include <bits/stdc++.h>

using namespace std;

/**
 * 题目130：被围绕的区域
 */

class Solution {
   public:
    /**
     * 思路：图的BFS或DFS 可以考虑非递归版本
     * 转换为寻找以边界上O开始的连通区域并设置为#
     */
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
                if (isEdge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 遇到O置为X
                if (board[i][j] == 'O') board[i][j] = 'X';
                // 遇到#置为O
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == 'X' || board[i][j] == '#')
            return;
        board[i][j] = '#';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};