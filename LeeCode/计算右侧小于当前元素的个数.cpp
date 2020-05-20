#include <bits/stdc++.h>

using namespace std;

/**
 * 题目：计算右侧小于当前元素的个数
 */

class Solution {
   public:
    
    vector<int> countSmaller(vector<int>& nums){}
    
    /**
     * 暴力法  超时！！
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     */
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for (int i = nums.size() - 2; i >= 0; i--) {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
                if (nums[j] < nums[i]) cnt++;
            res[i] = cnt;
        }
        return res;
    }
};