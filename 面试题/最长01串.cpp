#include <bits/stdc++.h>

using namespace std;

/**
 * 最长01串
 * 给定一个数组，数组中只包含0和1。请找到一个最长的子序列，其中0和1的数量是相同的。
 */

// 时间复杂度：O(n),空间复杂度：O(n)
vector<int> maxLen01(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
        if (nums[i] == 0) nums[i] = -1; // 把0换成-1，变成和为0的最长子数组
    unordered_map<int, int> hash;
    int a = -1, b = -1, maxlen = 0, pre = 0;
    hash[0] = -1; // 注意这儿的初始化
    for (int i = 0; i < n; i++) {
        pre += nums[i];
        if (hash.count(pre)) {
            if (maxlen < i - hash[pre]) {
                maxlen = i - hash[pre];
                a = hash[pre] + 1, b = i;
            }
        } else
            hash[pre] = i;
    }

    vector<int> res;
    for (int i = a; i <= b; i++) {
        res.push_back(nums[i] == -1 ? 0 : 1);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, 1, 1, 1, 1, 1, 1};
    vector<int> res = maxLen01(nums);
    for (auto n : res) cout << n << ' ';
}