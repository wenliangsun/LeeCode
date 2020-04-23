#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 希尔排序(缩小增量排序)
     */
    void ShellSort(vector<int>& nums, int left, int right) {
        int n = right - left + 1;
        // 缩小增量
        for (int gap = left + n / 2; gap > 0; gap /= 2) {
            // 采用插入排序算法进行排序
            for (int i = left + gap; i <= right; i++) {
                int j = i;
                int curSum = nums[i];
                while (j - gap >= left && curSum < nums[j - gap]) {
                    nums[j] = nums[j - gap];
                    j -= gap;
                }
                nums[j] = curSum;
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 1, 33, 43, 2, 2, 1, 23, 444};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.ShellSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}