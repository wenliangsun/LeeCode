#include <vector>

using namespace std;

/**
 * 题目45：跳跃游戏II
 */
class LeeCode45 {
   public:
    /**
     * 思路：贪心算法，挨个跳
     */
    int jump(vector<int>& nums) {
        int res = 0;    // 记录跳的次数
        int begin = 0;  // 开始位置
        int end = 1;    // 能跳到的位置
        while (end < nums.size()) {
            int temp = 0;
            // 寻找开始位置到当前能调到位置之间的可以调到的最远位置
            for (int i = begin; i < end; i++) {
                temp = max(temp, nums[i] + i);
            }
            // 更新起始位置
            begin = end;
            end = temp + 1;
            res++;
        }
        return res;
    }

    int jump2(vector<int>& nums) {
        int res = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            // 记录i-end之间可以跳跃的最远步数
            maxPos = max(maxPos, nums[i] + i);
            // 注意这个条件判断！！！
            // i和end标记了可以选择的跳跃步数
            if (i == end) {
                end = maxPos;
                res++;
            }
        }
        return res;
    }
};