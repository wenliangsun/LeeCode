#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1300：转变数组后最接近目标值的数组和
 */

class Solution {
   public:
    /**
     * 二分法
     */
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        // 注意这儿上下边界的确定
        int l = 0, r = *max_element(arr.begin(), arr.end());
        while (l < r) {
            int mid = l + r >> 1;
            if (check(arr, mid) >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return abs(check(arr, l - 1) - target) <= abs(check(arr, l) - target)
                   ? l - 1
                   : l;
    }

    int check(vector<int>& arr, int mid) {
        int res = 0;
        for (auto n : arr) {
            if (n > mid)
                res += mid;
            else
                res += n;
        }
        return res;
    }
};