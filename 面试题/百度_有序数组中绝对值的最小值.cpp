#include <bits/stdc++.h>

using namespace std;

/**
 * 线性扫描：时间复杂度O(n)，没有用到排序数组的性质
 */
int findAbsMin(vector<int>& nums) {
    int mv = INT_MAX, res = 0;
    for (auto n : nums) {
        if (abs(n) < mv) {
            mv = abs(n);
            res = n;
        }
    }
    return res;
}

/**
 * 二分的思想
 * 时间复杂度：O(logn)
 */
int findAbsMin2(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == 0) return nums[mid];
        else if (nums[mid] > 0) r = mid;
        else l = mid + 1;
    }
    if (abs(nums[l - 1]) < abs(nums[l])) return nums[l -1];
    else return nums[l];
}

int main() {
    vector<int> nums = {-9, -6, -5, -4, -3, -2, -1, 0, 1};
    int res = findAbsMin2(nums);
    cout << res << endl;
    return 0;
}