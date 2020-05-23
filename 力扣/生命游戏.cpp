#include <bits/stdc++.h>

using namespace std;

/**
 * 题目289：生命游戏
 */

class Solution {
   public:
    /**
     * 思路：采用复状态实现O(1)空间复杂度
     * 从0变成1 记为2  从1 变成 0  记为 -1
     */
    void gameOfLife(vector<vector<int>>& board) {
        int pos[3] = {0, -1, 1};
        int rows = board.size(), cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int cnt = 0;
                // 统计相邻邻域的1的个数
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (pos[i] == 0 && pos[j] == 0) continue;
                        int t_x = r + pos[i], t_y = c + pos[j];
                        if (t_x >= 0 && t_x < rows && t_y >= 0 && t_y < cols &&
                            abs(board[t_x][t_y]) == 1)
                            cnt++;
                    }
                }
                // 规则
                if (board[r][c] == 1 && (cnt < 2 || cnt > 3)) board[r][c] = -1;
                if (cnt == 3 && board[r][c] == 0) board[r][c] = 2;
            }
        }
        // 遍历数组 赋值
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};