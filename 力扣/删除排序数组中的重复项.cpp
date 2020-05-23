#include <vector>

using namespace std;

/**
 * 题目26：删除排序数组中的重复项
 */
class LeeCode26 {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0;       // 复制数字的位置
        int flag = nums[0];  // 记录不同的数字
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != flag) {
                flag = nums[i];
                index++;
                nums[index] = nums[i];
            }
        }
        index++;
        nums.erase(nums.begin() + index, nums.end());
        return index;
    }
};