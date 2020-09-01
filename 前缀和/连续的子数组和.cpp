#include <bits/stdc++.h>

using namespace std;

/**
 * 题目523：连续的子数组和
 */

class Solution {
public:
    /**
     * 前缀和 + 哈希表 + 同余定理
     * 同余定理：如果整数a和整数满足a-b能够被m整除，即(a-b)%m==0,则a对m取余与b对m取余相等，即a%m==b%m。
     * 如果两个数的差能被K整除，就说明这两个数 mod K得到的结果相同，
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            if (!k) pre %= k;
            if (hash.count(pre)) {
                if (i - hash[pre] > 1)
                    return true;
            } else hash[pre] = i;
        }
        return false;
    }

    /**
     * 前缀和
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1]; // 前缀和
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = pre[j] - pre[i];
                if (j - i > 1){
                    if (sum == k || (k && sum % k == 0)) return true;
                }
            }
        }
        return false;
    }
    // 暴力的话三层for循环，时间复杂度：O(n^3)
};