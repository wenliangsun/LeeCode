#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 冒泡排序
     */
    void BubbleSort(vector<int>& nums, int left, int right) {
        for (int i = left; i < right; i++) {
            bool flag = true; //用于判断是否交换
            for (int j = left; j < right - left; j++) {
                if (nums[j + 1] < nums[j]) {
                    int temp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 4, 1, 22, 32, 11, 323};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.BubbleSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}