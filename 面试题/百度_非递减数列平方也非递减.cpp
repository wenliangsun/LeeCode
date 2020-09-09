# include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 */


/**
 * 双指针
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
vector<int> helper(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> res(n);
    int idx = n - 1;
    while (l < r) {
        int a = nums[l] * nums[l];
        int b = nums[r] * nums[r];
        if (a > b) {
            res[idx] = a;
            l++;
        } else {
            res[idx] = b;
            r--;
        }
        idx--;
    }
    return res;
}

int main() {
    vector<int> nums = {-2, -1, 0, 3, 5, 6};
    vector<int> res = helper(nums);
    for (auto n : res) cout << n << ' ';
    return 0;
}