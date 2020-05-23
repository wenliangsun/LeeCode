#include <vector>

using namespace std;

/**
 * 题目48：旋转图像
 */
class LeeCode48 {
   public:
    /**
     * 思路:两次翻转
     * 先对角翻转，即转置；
     * 然后对每一行进行翻转。
     * 时间复杂度：O(n^2)
     */
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        // 转置
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i; j < matrix.size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 翻转每一行
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size() / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - j - 1];
                matrix[i][matrix.size() - j - 1] = temp;
            }
        }
    }

    /**
     * 思路：旋转坐标
     * 关于如何旋转的，好好斟酌！！！
     */
    void rotate2(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        // start 和 end 界定当前圈一行的起始和终止位置
        for (int start = 0, end = matrix.size() - 1; start < end;
             start++, end--) {
            // s,e 用于旋转四个坐标，旋转的次数小于当前圈的长度end
            for (int s = start, e = end; s < end; s++, e--) {
                int temp = matrix[start][s];
                matrix[start][s] = matrix[e][start];
                matrix[e][start] = matrix[end][e];
                matrix[end][e] = matrix[s][end];
                matrix[s][end] = temp;
            }
        }
    }
};