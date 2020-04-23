#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 选择排序
     */
    void SelectSort(vector<int>& nums, int left, int right) {
        int minIndex;
        for (int i = left; i <= right; i++) {
            minIndex = i;
            for (int j = i + 1; j <= right; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 34, 2, 1, 323, 123, 211, 222342, 43};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.SelectSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}