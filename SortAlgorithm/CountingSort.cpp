#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 计数排序
     */
    void CountingSort(vector<int>& nums, int maxValue) {
        vector<int> temp(maxValue + 1, 0);
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp[nums[i]]++;
        }
        for (int i = 0; i <= maxValue; i++) {
            while (temp[i] > 0) {
                nums[index++] = i;
                temp[i]--;
            }
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 1, 4, 5, 8, 9, 6, 7};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.CountingSort(nums, 9);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}