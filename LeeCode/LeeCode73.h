#include <vector>

using namespace std;

/**
 * 思路：矩阵置零
 */
class LeeCode73 {
   public:
    /**
     * 思路：使用两个数组记录x,y方向上的0的位置
     * 时间复杂度：O(MN)
     * 空间复杂度：O(M+N)
     */
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        vector<int> rows;  // 记录x方向上的0的位置
        vector<int> cols;  // 记录y方向上的0的位置
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (int i = 0; i < rows.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[rows[i]][j] = 0;
            }
        }
        for (int j = 0; j < cols.size(); j++) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][cols[j]] = 0;
            }
        }
    }

    /**
     * 思路：利用第一行和第一列进行标记
     * 如果数组中某个数字为0，则将当前行和当前列的第一个元素置零。
     * 时间复杂度：O(MN)
     * 空间复杂度：O(1)
     */
    void setZeroes2(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        bool isCols = false;  // 用于指示第一列是否需要置零
        for (int i = 0; i < matrix.size(); i++) {
            // 判断第一列是否有0
            if (matrix[i][0] == 0) {
                isCols = true;
            }
            // 如果是0的话，将其行和列的第一个元素置零
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 将行和列置零
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 如果0,0是0，则将行置零
        if (matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        // 如果列中有0，则将第一行置零
        if (isCols) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};