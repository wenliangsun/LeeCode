#include <stack>
#include <vector>

using namespace std;

/**
 * 题目85：最大矩形
 */
class LeeCode85 {
   public:
    /**
     * 思路：使用数据栈，借助柱状图中面积最大的矩形
     * 首先沿着某一维度累加1的个数(遇到0时重置)，可得到沿着另一维度的柱状图，每个位置的数字表示到当前位置有多少个1
     * 然后沿着另一个维度 按照柱状图中最大矩形求的最大矩形。
     * 时间复杂度：O(MN)
     * 空间复杂度：O(M)或O(N)
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> dp(cols, 0);
        int maxAera = 0;
        // 沿row方向累计1的个数
        for (int i = 0; i < rows; i++) {
            // 沿row方向累计所有col
            for (int j = 0; j < cols; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // 每累计一行，计算最大矩形
            maxAera = max(maxAera, largestRectangleArea(dp));
        }

        return maxAera;
    }

    /**
     * 思路：动态规划
     * 待开发！！！
     */
    int maximalRectangle2(vector<vector<char>>& matrix) {}

   private:
    /**
     * 题目84：柱状图中的最大矩形
     */
    int largestRectangleArea(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int maxAera = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < height.size(); i++) {
            while (stk.top() != -1 && height[i] <= height[stk.top()]) {
                int index = stk.top();
                stk.pop();
                maxAera = max(maxAera, (i - stk.top() - 1) * height[index]);
            }
            stk.push(i);
        }
        int len = height.size();
        while (stk.top() != -1) {
            int index = stk.top();
            stk.pop();
            maxAera = max(maxAera, (len - stk.top() - 1) * height[index]);
        }
        return maxAera;
    }
};
