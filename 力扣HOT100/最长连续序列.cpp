#include <bits/stdc++.h>

using namespace std;

/**
 * 最长连续序列
 */

class Solution {
   public:
    /**
     * 使用哈希表
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto n : nums) hash.insert(n);
        int res = 0;
        for (auto n : hash) { // 注意需要从set中枚举
            if (n == INT_MIN || !hash.count(n - 1)) {  // 从没有比当前数小一的数开始
                int len = 0;
                // 统计以当前数字开始的连续序列长度
                while (hash.count(n)) {
                    len++, n++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
    
    // 并查集
    unordered_map<int, int> p;
    int longestConsecutive(vector<int>& nums) {
        for (auto n : nums) p[n] = n + 1;
        int res = 0;
        for (auto n : nums) {
            int r = find(n + 1);
            res = max(res, r - n);
        }
        return res;
    }

    int find(int x) { return p.count(x) ? p[x] = find(p[x]) : x; }
};