#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：跳跃游戏II
 * 可用贪心 也可用 动态规划  但是贪心更优
 */
class Solution {
   public:
    /**
     * 贪心思路，容易理解版本
     */
    int jump(vector<int>& nums) {
        int res = 0;
        int begin = 0;  // 开始跳跃位置
        int end = 1;    // 结束跳跃位置
        while (end < nums.size()) {
            int temp = 0;
            // 寻找从开始到结束能跳的最远的位置  这部分可以优化
            for (int i = begin; i < end; i++) {
                temp = max(temp, nums[i] + i);
            }
            // 更新开始和结束位置
            begin = end;
            end = temp + 1;
            res++;
        }
        return res;
    }

    /**
     * 优化版本
     */
    int jump2(vector<int> nums) {
        int res = 0;
        int end = 0;
        int maxPos = 0;  // 记录从i到end区间中能跳到的最远距离
        for (int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end) {
                end = maxPos;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 1, 1, 4};
    int res = s.jump2(nums);
    cout << res << endl;
}