#include <stack>
#include <vector>

using namespace std;

/**
 * 题目42：接雨水
 */
class LeeCode42 {
   public:
    /**
     * 思路：按列求
     * 求每一列的水，只需要关注当前列，以及左边最高的墙和右边最高的墙即可
     * 木桶效应，我们只要左边最高和右边最高中的较矮的一个;
     * 然后用较矮的一个减去当前的高度即为当前列存储的水量.
     * 时间复杂度：O(n^2)。数组中的每个元素都需要向左向右扫描。
     * 空间复杂度：O(1)
     */
    int trap1(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }
        int res = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int max_left = 0;
            int max_right = 0;
            // 向左寻找最高墙, 主要从当前列开始
            for (int j = i; j >= 0; j--) {
                max_left = max(max_left, height[j]);
            }
            // 向右寻找最高墙， 注意从当前列开始
            for (int j = i; j < height.size(); j++) {
                max_right = max(max_right, height[j]);
            }
            // 计算当前列的储水量，并累加
            res += min(max_left, max_right) - height[i];
        }
        return res;
    }

    /**
     * 动态规划
     * 按列求时，对于每一列，我们求它左边最高的墙和右边最高的墙，
     * 都是重新遍历一遍所有高度，这里我们可以优化一下。
     * 时间复杂度O(n)
     * 空间复杂度O(n)
     */
    int trap2(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }
        int res = 0;
        int max_left[height.size()];
        int max_right[height.size()];
        max_left[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }
        max_right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }
        for (int i = 1; i < height.size() - 1; i++) {
            res += min(max_left[i], max_right[i]) - height[i];
        }
        return res;
    }

    /**
     * 双指针
     * 动态规划中，我们常常可以对空间复杂度进行进一步的优化。
     * 时间复杂度O(n)
     * 空间复杂度O(1)
     */
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int res = 0, l = 0, r = height.size() - 1, ml = 0, mr = 0;
        while (l < r) {
            if (height[l] < height[r]) { // 当右侧高于左侧，则储水量由左侧的最大值和当前值决定
                if (height[l] >= ml)  // 如果当前值大于左侧的最大值，则没有存储到水，更新左侧最大值
                    ml = height[l];
                else // 否则，计算当前墙的储水量
                    res += ml - height[l];
                l++;
            } else { // 若果左墙高于右墙，则储水量由右侧最大值和当前墙的高度决定
                if (height[r] >= mr) // 如果当前墙的高度大于右侧最大值，说明当前无储水，更新右侧最大值
                    mr = height[r];
                else // 否则利用最大值和当前墙的高度计算当前储水量
                    res += mr - height[r];
                r--;
            }
        }
        return res;
    }
    /**
     * 使用栈
     * 使用栈来追踪可能的最高墙，遍历数组，如果当前墙的高度低于栈顶墙，则入栈，
     * 否则当前栈顶元素出栈，相当于统计当前栈顶所对应的墙的储水量，
     * 注意此时计算储水量时需要考虑两墙之间的间隔。
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int trap(vector<int>& height) { // 单调栈
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); i++) {
            int last = 0;  // 记录之前的高度
            // 维护一个单调递减栈
            while (stk.size() && height[stk.top()] <= height[i]) {
                int t = stk.top();
                stk.pop();
                // 当前层的雨水
                res += (height[t] - last) * (i - t - 1);
                last = height[t];  // 之前的高度更新为当前高度
            }
            // 右边墙低于左边墙的情况
            if (stk.size()) res += (height[i] - last) * (i - stk.top() - 1);
            stk.push(i);
        }
        return res;
    }
};