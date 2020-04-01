//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER19_H
#define C__ALGORITHM_NEWCODER19_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER19_H
using std::vector;

/**
 * 题目19：顺时针打印矩阵
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 */
class NewCoder19 {
public:
    /**
     * 注意循环终止条件。
     * @param matrix
     * @return
     */
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        if (matrix.size() <= 0)
            return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;

        while (start * 2 < cols && start * 2 < rows) { // 打印一圈的终止条件
            res = printCircle(matrix, res, start); // 打印一圈
            start++;
        }
        return res;
    }

    /**
     * 注意打印各个边时的边界情况以及是否有这条边的情况。
     * @param matrix
     * @param res
     * @param start
     * @return
     */
    vector<int> printCircle(vector<vector<int>> matrix, vector<int> res, int start) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int endX = cols - start - 1;
        int endY = rows - start - 1;
        //打印上面一行
        for (int i = start; i <= endX; ++i) {
            res.push_back(matrix[start][i]);
        }
        // 打印右面一列
        if (start < endY) {
            for (int i = start + 1; i <= endY; ++i) {
                res.push_back(matrix[i][endX]);
            }
        }
        // 打印下面一行
        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; --i) {
                res.push_back(matrix[endY][i]);
            }
        }
        // 打印左侧一列
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i > start; --i) {
                res.push_back(matrix[i][start]);
            }
        }
        return res;
    }
};