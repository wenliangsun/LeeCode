#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 快速排序
     */
    void QuickSort(vector<int>& nums, int left, int right) {
        // 注意这个条件
        if (left < right) {
            int index = partition(nums, left, right);
            QuickSort(nums, left, index - 1);
            QuickSort(nums, index + 1, right);
        }
    }

   private:
    /**
     * 快排的核心函数
     * 完成设置一个标志位，使得比它小的都在它前面，比它大的都在它后面
     */
    int partition(vector<int>& nums, int left, int right) {
        int flag = left;  // 标志位
        int index = left + 1;
        for (int i = index; i <= right; i++) {
            if (nums[i] < nums[flag]) {
                swap(nums, i, index);
                index++;
            }
        }
        // 把标志位放回到其应该所处的位置
        swap(nums, flag, index - 1);
        return index - 1;
    }

    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 4, 51, 3, 2, 32, 3232343, 232};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.QuickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}