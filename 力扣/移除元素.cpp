#include <vector>

using namespace std;

/**
 * 题目27：移除元素
 */
class LeeCode27 {
   public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        nums.erase(nums.begin() + index, nums.end());
        return index;
    }
};