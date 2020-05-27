#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1239：串联字符串的最大长度
 */

class Solution {
   public:
    /**
     * 回溯  深搜 + 位压缩
     */
    int maxLength(vector<string>& arr) { return dfs(arr, 0, 0); }

    int dfs(vector<string>& arr, int idx, int m) {
        if (idx == arr.size()) return 0;
        int t = m;  // 记录状态
        // 判断当前字符串中是否有重复字符
        for (auto c : arr[idx]) {
            // 如果有重复字符，则跳过当前字符串，状态使用之前记录的状态
            if (m & (1 << (c - 'a'))) return dfs(arr, idx + 1, t);
            m |= 1 << c - 'a';
        }
        int len = arr[idx].size();  // 当前字符串的长度
        // 对于当前字符串可以选择用，也可选择不用，取两者之间的最大值
        return max(len + dfs(arr, idx + 1, m), dfs(arr, idx + 1, t));
    }
};