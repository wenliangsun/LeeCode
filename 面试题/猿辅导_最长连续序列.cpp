#include <bits/stdc++.h>

using namespace std;

/**
 * 题目128：最长连续序列
 */

class Solution {
   public:
    /**
     * 利用哈希表
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto n : nums) hash.insert(n);
        int res = 0;
        for (auto n : nums) {
            if (!hash.count(n - 1)) {
                int cnt = 0;
                while (hash.count(n)) {
                    cnt++, n++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100, 4, 200,1 ,3,2};
    Solution s = Solution();
    int res = s.longestConsecutive(nums);
    cout << res << endl;
    return 0;
}