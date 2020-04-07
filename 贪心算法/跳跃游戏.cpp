#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：跳跃游戏
 */
class Solution {
   public:
    /**
     * 贪心思路
     */
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前距离大于上一次跳的最远距离，说明跳不到当前位置，返回false
            // 注意这儿的判断顺序
            if (i > maxPos) {
                return false;
            }
            // 不断计算能跳到的最远距离
            maxPos = max(maxPos, nums[i] + i);
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {3, 2, 1, 0, 4};
    bool res = s.canJump(nums);
    cout << res << endl;
}