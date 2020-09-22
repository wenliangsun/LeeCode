#include <bits/stdc++.h>

using namespace std;

/**
 * 找出有序数组中最接近给定目标数的下标
 * 输入：[1,2,3,3,4,5,6,7,8]    3
 * 输出：2
 * 
 * 输入：[1,3,5,7,9]    4
 * 输出：1
 */

class Solution{
    public:
    int findNearest(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int target, int l, int r) {
        if (l >= r) return l;
        int mid = (l + r) >> 1;
        int mv = nums[mid];
        int lv = nums[mid - 1 < l ? l : mid - 1];
        int rv = nums[mid + 1 > r ? r : mid + 1];
        int sm = abs(target - mv);
        int sl = abs(target - lv);
        int sr = abs(target - rv);
        if (sm < sl && sm < sr) return mid;
        else {
            int lidx = helper(nums, target, l, mid - 1);
            int ridx = helper(nums, target, mid + 1, r);
            if (abs(target - nums[lidx]) < abs(target - nums[r])) return lidx;
            else return ridx;
        }
    }
};