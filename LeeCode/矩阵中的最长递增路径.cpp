#include <bits/stdc++.h>

using namespace std;

/**
 * 题目329：矩阵中的最长递增路径的长度
 */

class Solution {
   public:
    /**
     * 带备忘录的深搜
     */
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;
        int res = 0;
        vector<vector<int>> memo(matrix.size(),
                                 vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs2(matrix, i, j, memo));
            }
        }
        return res;
    }

    int dfs2(vector<vector<int>>& matrix, int i, int j,
             vector<vector<int>>& memo) {
        int r = matrix.size(), c = matrix[0].size();
        if (memo[i][j]) return memo[i][j];
        if (i + 1 < r && matrix[i + 1][j] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs2(matrix, i + 1, j, memo));
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs2(matrix, i - 1, j, memo));
        if (j + 1 < c && matrix[i][j + 1] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs2(matrix, i, j + 1, memo));
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            memo[i][j] = max(memo[i][j], dfs2(matrix, i, j - 1, memo));

        return ++memo[i][j];
    }

    /**
     * 暴力 深搜  超时！！！
     */
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        int r = matrix.size(), c = matrix[0].size();
        int tmp = 0;
        if (i + 1 < r && matrix[i + 1][j] > matrix[i][j])
            tmp = max(tmp, dfs(matrix, i + 1, j));
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            tmp = max(tmp, dfs(matrix, i - 1, j));
        if (j + 1 < c && matrix[i][j + 1] > matrix[i][j])
            tmp = max(tmp, dfs(matrix, i, j + 1));
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            tmp = max(tmp, dfs(matrix, i, j - 1));
        tmp++;
        return tmp;
    }
};