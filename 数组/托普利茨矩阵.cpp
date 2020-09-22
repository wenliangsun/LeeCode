#include <bits/stdc++.h>

using namespace std;

/**
 * 题目766：托普利茨矩阵
 */

class Solution {
   public:
    /**
     * 判断其左上角是否和当前相等
     */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0 && matrix[i - 1][j - 1] != matrix[i][j])
                    return false;
            }
        }
        return true;
    }
};