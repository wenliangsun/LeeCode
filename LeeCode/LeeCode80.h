#include <vector>

using namespace std;

/**
 * 题目80：删除排序数组中的重复项II
 */
class LeeCode80 {
   public:
    /**
     * 思路：删除重复项
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0;       // 复制位置的索引
        int flag = nums[0];  // 标志新的不同的数字
        int count = 1;       // 统计数字出现的次数
        for (int i = 1; i < nums.size(); i++) {
            // 如果当前数字与前一个数字的不同，则重新设置flag，计数
            if (nums[i] != flag) {
                flag = nums[i];
                count = 1;
                index++;
                nums[index] = nums[i];
                // 如果计数少于2的话，新增计数
            } else if (count < 2) {
                count++;
                index++;
                nums[index] = nums[i];
            }
        }
        index++;
        nums.erase(nums.begin() + index, nums.end());
        return index;
    }
};