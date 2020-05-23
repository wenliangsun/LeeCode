#include <bits/stdc++.h>

using namespace std;

/**
 * 题目240：搜索二维矩阵II
 */

class Solution {
   public:
    /**
     * 思路：不同于搜索二维矩阵中的条件，那个可以使用二分搜索来完成，但是这个题目中的
     * 题目不符合二分的要求。我们可以利用排序的特点来完成。
     * 时间复杂度：O(MN)
     * 空间复杂度：O(1)
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int r = 0, c = matrix[0].size() - 1;
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else
                r++;
        }
        return false;
    }
};