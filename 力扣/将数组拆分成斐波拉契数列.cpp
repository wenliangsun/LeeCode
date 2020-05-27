#include <bits/stdc++.h>

using namespace std;

/**
 * 题目842：将数组拆分成斐波拉契数列
 */

class Solution {
   public:
    vector<int> res;

    /**
     * 回溯 + 剪枝 和 306题有点类似
     */
    vector<int> splitIntoFibonacci(string S) {
        vector<int> path;
        if (S.size()) {
            dfs(S, 0, path);
        }
        return res;
    }

    void dfs(string& s, int idx, vector<int>& path) {
        if (idx == s.size()) {
            // 如果数字大于2 说明符合条件
            if (path.size() > 2) res = path;
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            int n = path.size();
            // 获取当前数字对应的字符串
            string st = s.substr(idx, i - idx + 1);
            //  剪枝第一个是位置是 0 的情况
            if (idx < i && st[0] == '0') continue;
            long long t = stoll(st);  // 转数字
            if (t > INT_MAX) break;   // 如果当前数字大于 INT_MAX 剪枝
            // 如果前两项的和大于 INT_MAX 剪枝
            if (n >= 2 && (long long)path[n - 1] + path[n - 2] > INT_MAX) break;
            // 如果当前数字大于前两项的和 剪枝
            if (n >= 2 && t > (long long)path[n - 1] + path[n - 2]) break;
            // 如果满足条件  则dfs
            if (n <= 1 || t == path[n - 1] + path[n - 2]) {
                path.push_back(t);
                dfs(s, i + 1, path);
                path.pop_back();
            }
        }
    }
};