#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 插入排序
     */
    void InsertSort(vector<int>& nums, int left, int right) {
        for (int i = left; i <= right; i++) {
            int j = i - 1;
            int curnum = nums[i];
            while (j >= left && curnum < nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = curnum;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 45, 1, 32, 22, 123, 31, 323, 4444, 232, 122222};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.InsertSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}