#include <bits/stdc++.h>

using namespace std;

/**
 * 前缀和 + 哈希表
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
int numOfSumK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hash;
    int pre = 0;
    int res = 0;
    hash[0] = 1;
    for (auto n : nums) {
        pre += n;
        if (hash.count(pre - k)) res += hash[pre - k];
        hash[pre]++;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int res = numOfSumK(nums, 2);
    cout << res << endl;
    return 0;
}