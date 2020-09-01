#include <bits/stdc++.h>

using namespace std;

/**
 * 和为k的子数组
 */

class Solution {
   public:
    /**
     * 前缀和
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int subarraySum(vector<int>& nums, int k) {
        if (!nums.size()) return 0;
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (pre[j] - pre[i] == k) res++;
            }
        }
        return res;
    }

    /**
     * 前缀和 + 哈希表
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     * sum[j] - sum[i] = k --> sum[i] = sum[j]- k,即变为去找sum[i]出现的次数。
     */
    int subarraySum(vector<int>& nums, int k) {
        if (!nums.size()) return 0;
        unordered_map<int, int> hash;
        hash[0] = 1;
        int pre = 0, res = 0;
        for (auto n : nums) {
            pre += n;
            if (hash.count(pre - k)) res += hash[pre - k];
            hash[pre]++;
        }
        return res;
    }
};