#include <bits/stdc++.h>

using namespace std;

/**
 * 题目665：非递减数列
 */

class Solution {
   public:
    /**
     * 找到一个元素大于后面的那个元素
     * 有两种情况：(1)改变当前元素才能成为非递减序列；(2)改变当前元素后面的那个元素才能成为非递减元素
     */
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) { // 前面一个元素大于当前元素时，
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) // 如果前面的前面的元素大于当前元素，则把当前元素改为前一个元素
                    nums[i] = nums[i - 1];
                else // 否则把前一个元素改成当前元素,这样改了之后不会影响数组中之后元素的判断
                    nums[i - 1] = nums[i];
                cnt++;
            }
        }
        return cnt <= 1;
    }
};