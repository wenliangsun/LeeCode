#include <bits/stdc++.h>

using namespace std;

/**
 * 题目376：摆动排序
 */

class Solution {
public:
    /**
     * 动态规划：
     * up[i]表示以i为结尾的且上升的摆动序列的长度
     * down[i]表示以i为结尾的且下降的摆动序列的长度
     * 类似最长增长子序列的更新方式
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        vector<int> up(n), down(n);
        for (int i = 0; i < n; i++) {
            up[i] = 1, down[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) up[i] = max(up[i], down[j] + 1);
                else if (nums[i] < nums[j]) down[i] = max(down[i], up[j] + 1);
            }
        }
        return max(up[n - 1], down[n - 1]);
    }

    /**
     * 考虑up一定是从down(除初始状态)中产生的，并且此时的down是最大的.
     * 假设down[i]表示的最远末尾元素下标刚好是i，则up[i+1] = down[i] + 1;
     * 假设down[i]表示的最远末尾元素下标小于i，记为j，则i到j之间一定是递增的，因为如果有递减，
     * 则down[i]表示的最远末尾元素就不是j了。所以down[j:i]一直都是down[j]，所以此时依然满足up[i+1] = down[i]+1.
     * 其余情况类似。注意到down和up只和前一个状态有关，所以我们可以优化存储，分别用一个变量即可。
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) down = up + 1;
            else if (nums[i] > nums[i - 1]) up = down + 1;
        }
        return max(up, down);
    }
};

