#include <bits/stdc++.h>

using namespace std;

/**
 * 题目52：N皇后II
 */

class Solution {
   public:
    /**
     * 依次枚举每一行皇后的位置
     * 1. 每一列只能有一个皇后 col[N]
     * 2. 每条斜线上只能有一个皇后 d[2N] ud[2N] 有2N-1条斜线
     * x+y 表示反向斜线  x-y+n 表示正向斜线  这个很秀！！！
     */
    vector<bool> col, d, ud;  // 列 正斜线 反斜线
    int res = 0;
    int totalNQueens(int n) {
        col = vector<bool>(n);
        d = vector<bool>(2 * n);
        ud = vector<bool>(2 * n);
        dfs(0, n);  // dfs 每一行
        return res;
    }

    void dfs(int u, int n) {
        if (u == n) {
            res++;
            return;
        }
        // 遍历每一列
        for (int i = 0; i < n; i++) {
            // 判断当前列能否放置
            if (!col[i] && !d[u + i] && !ud[u - i + n]) {
                col[i] = true, d[u + i] = true, ud[u - i + n] = true;
                dfs(u + 1, n);
                col[i] = false, d[u + i] = false, ud[u - i + n] = false;
            }
        }
    }
};