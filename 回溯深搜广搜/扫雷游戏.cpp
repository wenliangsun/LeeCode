#include <bits/stdc++.h>

using namespace std;

/**
 * 题目529：扫雷游戏
 */

class Solution {
   public:
    int m, n;
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] == 'E') { //如果是E
            board[x][y] = 'B'; // 先标记为B
            int cnt = judge(board, x, y); // 统计当前位置相邻的雷的数量
            if (cnt == 0) { // 如果雷的数量为零，则dfs
                for (int i = 0; i < 8; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a >= 0 && a < m && b >= 0 && b < n) dfs(board, a, b);
                }
            } else // 否则标记当前位置为雷的数量
                board[x][y] = cnt + '0';
        } else if (board[x][y] == 'M') // 如果是雷M
            board[x][y] = 'X'; // 设置标记为X
    }

    // 统计当前位置相邻雷的数量
    int judge(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'M') cnt++;
        }
        return cnt;
    }
};