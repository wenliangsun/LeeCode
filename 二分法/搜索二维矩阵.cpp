#include <vector>

using namespace std;

/**
 * 编写一个高效的算法来判断 m x n
 * 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 */

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (matrix[mid / m][mid % m] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (matrix[l / m][l % m] != target) return false;
        return true;
    }
};