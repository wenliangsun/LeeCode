#include <vector>

using namespace std;

/**
 * 题目59：螺旋矩阵II
 */
class LeeCode59 {
   public:
    /**
     * 思路：利用螺旋打印数组思路的逆思路，即不是打印而是赋值
     */
    vector<vector<int>> generateMatrix(int n) {
        // 初始化矩阵
        vector<vector<int>> res(n, vector<int>(n));
        if (n <= 0) {
            return res;
        }
        int start = 0;
        int num = 1;
        // 一圈一圈赋值
        while (start * 2 < n) {
            genCircle(res, start, num);
            start++;
        }
        return res;
    }

   private:
    /**
     * 一圈赋值
     */
    void genCircle(vector<vector<int>>& res, int start, int& num) {
        int n = res.size();
        int endX = n - start - 1;
        int endY = n - start - 1;
        for (int i = start; i <= endX; i++) {
            res[start][i] = num;
            num++;
        }
        for (int i = start + 1; i <= endY; i++) {
            res[i][endX] = num;
            num++;
        }
        for (int i = endX - 1; i >= start; i--) {
            res[endY][i] = num;
            num++;
        }
        for (int i = endY - 1; i > start; i--) {
            res[i][start] = num;
            num++;
        }
    }
};