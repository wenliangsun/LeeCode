#include <vector>

using namespace std;

/**
 * 题目74：搜索二维矩阵
 */
class LeeCode74 {
   public:
    /**
     * 思路：利用排序的条件查找
     * 时间复杂度：O(MN)
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int row = 0;
        int col = matrix[0].size() - 1;
        while (col >= 0 && row < matrix.size()) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }

    /**
     * 思路：二维矩阵的二分搜索
     * 注意二分搜索的终止条件，力扣上面有总结！！！
     * 时间复杂度：O(log(MN))
     */
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int numMid = matrix[mid / col][mid % col];
            if (numMid == target) {
                return true;
            } else if (numMid > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};