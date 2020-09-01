#include <bits/stdc++.h>

using namespace std;

/**
 * 题目885：螺旋矩阵III
 */

class Solution {
   public:
    /**
     * 思路：不要局限于给定的网格，我们从起点开始螺旋打印，如果遍历到的位置在给定的网格中，就将当前位置添加到答案中
     * 每次一个方向走的步数的规律是1122334455667788，可以发现，每换两个方向，就需要多走一次。
     */
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> spiralMatrixIII(int R, int C, int x, int y) {
        vector<vector<int>> res(R * C);
        // d 表示方向，cnt记录在当前方向上走的步数，mxcnt记录当前方向上最多走的步数，dcnt记录换方向的次数，idx是答案的索引
        int d = 0, cnt = 0, mxcnt = 1, dcnt = 0, idx = 0;
        res[0] = {x, y};
        while (idx < R * C - 1) {
            x  = x + dx[d], y = y + dy[d]; // 更新位置
            if (x >= 0 && x < R && y >= 0 && y < C) res[++idx] = {x, y}; // 如果当前位置在网格中则记录答案
            cnt++; // 当前方向上走的步数+1
            if (cnt == mxcnt) { // 如果当前方向走到最大步数，则需要换方向
                d = (d + 1) % 4; // 换方向
                cnt = 0; // 新方向上走的步数
                dcnt++; // 换方向的次数
            }
            if (dcnt == 2) { // 如果换了两次
                mxcnt++; // 最大步数需要+1
                dcnt = 0;
            }
        }
        return res;
    }
};