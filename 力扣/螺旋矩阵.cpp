#include <vector>

using namespace std;

/**
 * 题目54：螺旋矩阵
 */
class LeeCode54 {
   public:
    /**
     * 模拟法 代码简洁
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size()) return res;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;  // d用来表示方向
        for (int i = 1; i <= n * m; i++) {
            int nx = x + dx[d], ny = y + dy[d];  //计算下一个位置
            // 如果超出边界，则需要换方向
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny]) {
                d = (d + 1) % 4;  // 更换方向
                nx = x + dx[d], ny = y + dy[d];
            }
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            x = nx, y = ny;
        }
        return res;
    }

    /**
     * 模拟法  代码复杂！！！
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