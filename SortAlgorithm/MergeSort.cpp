#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 归并排序
     * 思想来源于分治法
     */
    void MergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }

   private:
    /**
     * 核心函数
     */
    void Merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(nums.size());
        int tempIndex = left;
        int rightIndex = mid + 1;
        int curIndex = left;
        while (left <= mid && rightIndex <= right) {
            if (nums[left] < nums[rightIndex]) {
                temp[curIndex++] = nums[left++];
            } else {
                temp[curIndex++] = nums[rightIndex++];
            }
        }
        while (left <= mid) {
            temp[curIndex++] = nums[left++];
        }
        while (rightIndex <= right) {
            temp[curIndex++] = nums[rightIndex++];
        }
        while (tempIndex <= right) {
            nums[tempIndex] = temp[tempIndex];
            tempIndex++;
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 3, 43, 1, 232, 431, 3, 21, 2444};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.MergeSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}