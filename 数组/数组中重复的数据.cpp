#include <bits/stdc++.h>

using namespace std;

/**
 * 题目442：数组中重复的数据
 */

class Solution {
   public:
    /**
     * 利用题目中所给信息 1 ≤ a[i] ≤ n
     * 将出现过的数字作为数组的index（访问元素时需要减一），如果出现一次的，
     * 将该index下的数取相反数，记录此时的状态，如果值为index的数字再出现一次（此时index索引的值为负数），
     * 那么这个数字就出现了两次。
     */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums) {
            n = abs(n);
            if (nums[n - 1] < 0)
                res.push_back(n);
            else
                nums[n - 1] = -nums[n - 1];
        }
        return res;
    }
};