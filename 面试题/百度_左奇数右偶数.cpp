#include <bits/stdc++.h>

using namespace std;

/**
 * 左奇数右偶数
 */

// 快慢指针 在原数组上操作 O(n)
vector<int> exchange(vector<int>& nums) {
    for (int i = 0, j = 0; j < nums.size(); j++) {
        if (nums[j] & 1) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return nums;
}

// 新开一个数组
vector<int> exchange2(vector<int>& nums) {
    vector<int> res;
    for (auto n : nums)
        if (n & 1) res.push_back(n);
    for (auto n : nums)
        if (!(n & 1)) res.push_back(n);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    vector<int> res = exchange2(nums);
    for (auto n : res) cout << n << ' ';
    return 0;
}