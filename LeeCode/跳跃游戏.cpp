#include <vector>

using namespace std;

/**
 * 题目55：跳跃游戏
 */
class LeeCode55 {
   public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxPos) {
                return false;
            }
            maxPos = max(maxPos, nums[i] + i);
        }
        return true;
    }
};