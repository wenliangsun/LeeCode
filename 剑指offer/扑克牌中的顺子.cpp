#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 首先对数组进行排序，然后统计0出现的次数，再统计间隔的数量，比较0的数量和间隔的数量
     */
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 排序
        int nzeros = 0;                  // 记录0的次数
        for (auto n : nums)              // 统计0出现的次数
            if (!n) nzeros++;
        int ngap = 0;  //记录间隔的数量
        // 统计间隔的数量
        for (int i = nzeros, j = nzeros + 1; j < nums.size(); i++, j++) {
            if (nums[i] == nums[j]) return false;
            ngap += nums[j] - nums[i] - 1;
        }
        return ngap <= nzeros;
    }
};