#include <bits/stdc++.h>

using namespace std;

/**
 * 题目304：二维区域和检索-矩阵不可变
 */

class NumMatrix {
public:
    // 二维前缀和
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col1 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};