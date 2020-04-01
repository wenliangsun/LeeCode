#include <climits>
#include <stack>
#include <vector>

using namespace std;

/**
 * 题目84：柱状图中最大的矩形
 */
class LeeCode84 {
   public:
    /**
     * 思路：暴力法
     * 从左到右边遍历每个区间，
     * 寻找区间中的最低高度
     * 更新最大的面积
     * 时间复杂度：O(n^3)
     * 空间复杂度：O(1)
     */
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        int maxAera = 0;
        // 左边界
        for (int i = 0; i < heights.size(); i++) {
            // 右边界
            for (int j = i; j < heights.size(); j++) {
                int minHeight = INT_MAX;
                // 寻找左右边界之间的最低高度
                for (int k = i; k <= j; k++) {
                    if (heights[k] < minHeight) {
                        minHeight = heights[k];
                    }
                }
                // 更新最大面积
                maxAera = max(maxAera, (j - i + 1) * minHeight);
            }
        }
        return maxAera;
    }

    /**
     * 思路：优化版本的暴力法
     * 暴力法更新区间时都需要遍历区间寻找最低高度
     * 我们可以考虑使用一个变量来更新最小高度，不需要重头开始遍历
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     */
    int largestRectangleArea2(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        int maxAera = 0;
        for (int i = 0; i < heights.size(); i++) {
            int minHeight = INT_MAX;  // 记录最低高度
            for (int j = i; j < heights.size(); j++) {
                // 更新当前区间的最低高度
                minHeight = min(minHeight, heights[j]);
                // 更新最大值
                maxAera = max(maxAera, (j - i + 1) * minHeight);
            }
        }
        return maxAera;
    }

    /**
     * 思路：分治法
     * 确定了最矮柱子后，矩形的宽尽可能向两边延伸，
     * 在最矮柱子左边的最大面积矩形(子问题)
     * 在最矮柱子右边的最大面积矩形(子问题)
     * 时间复杂度：O(nlogn) 最坏情况O(n^2)
     * 空间复杂度：O(n) 需要 O(n)的递归时间
     */
    int largestRectangleArea3(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        return calculateAera(heights, 0, heights.size() - 1);
    }

    /**
     * 思路：利用栈数据结构 
     * 维护一个单调递增的栈来确定左右边界
     * 时间复杂度：O(n) 每个高度只需要遍历一次
     * 空间复杂度：O(n) 栈的空间
     */
    int largestRectangleArea4(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        stack<int> stk;
        stk.push(-1);  // 哨兵？ 怎么理解？
        int maxAera = 0;
        for (int i = 0; i < heights.size(); i++) {
            // 如果当前高度小于栈顶高度则出栈，计算以当前元素为高的矩形面积
            while (stk.top() != -1 && heights[i] <= heights[stk.top()]) {
                int index = stk.top();  // 注意这儿先出栈再用栈顶的索引
                stk.pop();
                maxAera = max(maxAera, (i - index - 1) * heights[stk.top()]);
            }
            // 否则，入栈
            stk.push(i);
        }
        int len = heights.size();
        // 计算栈内元素高度
        while (stk.top() != -1) {
            int index = stk.top();  // 注意
            stk.pop();
            maxAera = max(maxAera, (heights[index] * (len - stk.top() - 1)));
        }
        return maxAera;
    }

   private:
    // 计算区间中的最大面积矩形
    int calculateAera(vector<int>& heights, int begin, int end) {
        if (begin > end) {
            return 0;
        }
        int minIndex = begin;
        // 寻找当前区间的最小值
        for (int i = begin; i <= end; i++) {
            if (heights[minIndex] > heights[i]) {
                minIndex = i;
            }
        }
        // 返回当前区间和左右区间中的最大面积矩形
        return max(heights[minIndex] * (end - begin + 1),
                   max(calculateAera(heights, begin, minIndex - 1),
                       calculateAera(heights, minIndex + 1, end)));
    }
};