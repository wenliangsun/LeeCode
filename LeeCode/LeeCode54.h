#include <vector>

using namespace std;

/**
 * 题目54：螺旋矩阵
 */
class LeeCode54 {
   public:
    /**
     * 注意边界情况
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return res;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        while (left * 2 < rows && left * 2 < cols) {
            printCircle(matrix, left);
            left++;
        }
        return res;
    }

   private:
    vector<int> res;
    void printCircle(vector<vector<int>> matrix, int left) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int endX = cols - left - 1;
        int endY = rows - left - 1;
        for (int i = left; i <= endX; i++) {
            res.push_back(matrix[left][i]);
        }
        if (left < endY) {
            for (int i = left + 1; i <= endY; i++) {
                res.push_back(matrix[i][endX]);
            }
        }
        if (left < endY && left < endX) {
            for (int i = endX - 1; i >= left; i--) {
                res.push_back(matrix[endY][i]);
            }
        }
        if (left < endX && left < endY - 1) {
            for (int i = endX - 1; i > left; i--) {
                res.push_back(matrix[i][left]);
            }
        }
    }
};