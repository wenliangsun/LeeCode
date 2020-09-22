#include <bits/stdc++.h>

using namespace std;

/**
 * 题目340：至少包含k个不同字符的最长子串
 * 
 * 给定字符串S，找到最多有k个不同字符的最长子串T。
 * eceda k=2 输出：3 (ece)
 */

class Solution {
   public:
    /**
     * 思路：滑动窗口 双指针
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int l = 0, r = 0;
        unordered_map<char, int> hash;
        while (r < s.size()) {
            hash[s[r]]++;
            r++;
            while (hash.size() > k) {
                hash[s[l]]--;
                if (hash[s[l]] == 0) hash.erase(s[l]);
                l++;
            }
            res = max(res, r - l);
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    string str = "eceda";
    int res = s.lengthOfLongestSubstringKDistinct(str, 2);
    cout << res << endl;
}