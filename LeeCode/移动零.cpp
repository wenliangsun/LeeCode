#include <bits/stdc++.h>

using namespace std;

/**
 * 题目283：移动零
 */

class Solution {
   public:
    // 先把非零的元素移动到前面，然后将后面的位置置零
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        // 将非零元素移动到前面
        for (int i = 0; i < nums.size(); i++)
            if (nums[i]) nums[idx++] = nums[i];
        // 将后面的元素置零
        for (int i = idx; i < nums.size(); i++) nums[i] = 0;
    }
};