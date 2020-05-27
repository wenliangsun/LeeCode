#include <bits/stdc++.h>

using namespace std;

/**
 * 题目51：N皇后
 */

class Solution {
   public:
    /**
     * 依次枚举每一行皇后的位置
     * 1. 每一列只能有一个皇后 col[N]
     * 2. 每条斜线上只能有一个皇后 d[2N] ud[2N] 有2N-1条斜线
     * x+y 表示反向斜线  x-y+n 表示正向斜线  这个很秀！！！
     */
    vector<vector<string>> res;  // 记录所有答案
    vector<string> tmp;          // 记录当前方案
    vector<bool> col, d, ud;     // 列， 正斜线， 反斜线

    vector<vector<string>> solveNQueens(int n) {
        string line(n, '.');  // 当前行
        col = vector<bool>(n);
        d = vector<bool>(2 * n);
        ud = vector<bool>(2 * n);
        dfs(line, 0, n);  // dfs 每一行
        return res;
    }

    void dfs(string& line, int u, int n) {
        // 如果到达最后一行，则记录答案
        if (u == n) {
            res.push_back(tmp);
            return;
        }
        // 遍历每一列
        for (int i = 0; i < n; i++) {
            // 判断当前行能否放置皇后
            if (!col[i] && !d[u + i] && !ud[u - i + n]) {
                line[i] = 'Q';        // 放置皇后
                tmp.push_back(line);  // 添加当前行
                line[i] = '.';        // 新的一行
                col[i] = true, d[u + i] = true, ud[u - i + n] = true;
                dfs(line, u + 1, n);
                col[i] = false, d[u + i] = false, ud[u - i + n] = false;
                tmp.pop_back();
            }
        }
    }
};