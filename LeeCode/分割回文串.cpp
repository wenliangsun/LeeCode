#include <bits/stdc++.h>

using namespace std;

/**
 * 题目131：分割回文串
 */

class Solution {
    vector<vector<string>> res;

   public:
    // 回溯法 + 剪枝
    // 每个节点表示截取剩余的字符串
    // 产生前缀字符串时，判断前缀是否是回文，如果是回文，则分割，否则，剪枝
    // 叶子结点是空字符串时，此时，从根节点到叶结点的路径就是结果集中的一个解。
    vector<vector<string>> partition(string s) {
        if (s.empty()) return res;
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(string s, int begin, vector<string> path) {
        // 到达叶子节点
        if (begin == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            // 判断前缀是否是回文，不是回文则剪枝
            // 这儿需要每次判断回文，可以在这儿做优化，把回文的结果保存起来
            if (!check(s, begin, i)) continue;
            // 回溯法标准模板！！！
            path.push_back(s.substr(begin, i - begin + 1));
            dfs(s, i + 1, path);
            path.pop_back();
        }
    }
    // 判断子串是否是回文
    bool check(string s, int b, int e) {
        while (b < e) {
            if (s[b] != s[e]) return false;
            b++, e--;
        }
        return true;
    }
};