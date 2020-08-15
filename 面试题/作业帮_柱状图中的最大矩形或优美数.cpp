#include <bits/stdc++.h>

using namespace std;

/**
 * 定义一个“优美数”：任意一个区间的长度乘以这个区间的最小值，返回数组中的最大的优美数。时间复杂度为O(n);
 * 其实就是柱状图中的最大矩形
 * 单调栈
 */

class Solution {
    public:
    int greatNum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && nums[stk.top()] >= nums[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && nums[stk.top()] >= nums[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, nums[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {3, 1, 6, 4, 5, 2};
    int res = s.greatNum(nums);
    cout << res << endl;
    return 0;
}