#include <bits/stdc++.h>

using namespace std;

/**
 * 题目212：单词搜索II
 */

class Solution {
   public:
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    vector<vector<bool>> st;
    // 回溯法超时
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> res;
        if (!board.size() || !board[0].size()) return res;
        m = board.size(), n = board[0].size();
        for (auto w : words) {
            st = vector<vector<bool>>(m, vector<bool>(n));
            bool flag = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == w[0] && dfs(board, i, j, 0, w))
                        flag = true;
                }
            }
            if (flag) res.push_back(w);
        }
        return res;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, int idx,
             string& words) {
        if (board[x][y] != words[idx] || st[x][y]) return false;
        if (idx == words.size() - 1) return true;
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n) {
                if (dfs(board, a, b, idx + 1, words)) return true;
            }
        }
        st[x][y] = false;
        return false;
    }
};