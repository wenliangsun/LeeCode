#include <bits/stdc++.h>

using namespace std;

/**
 * 和为k的子数组
 */

class Solution {
   public:
    /**
     * 双指针
     * 固定左端点，移动右端点
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     */
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) res++;
            }
        }
        return res;
    }

    /**
     * 以i为终点的子数组
     */
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                if (sum == k) res++;
            }
        }
        return res;
    }

    /**
     * 前缀和 + 优化
     * 如果区间j，i满足和为k，则pre[i]-pre[j-1] == k,所以 pre[j-1] = pre[i] - k;
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int pre = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (hash.count(pre - k)) res += hash[pre - k];
            hash[pre]++;
        }
        return res;
    }
};