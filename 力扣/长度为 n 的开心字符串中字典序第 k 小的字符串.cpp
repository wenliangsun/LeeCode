#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1415：长度为 n 的开心字符串中字典序第 k 小的字符串
 */

class Solution {
   public:
    string res;
    int cnt = 0;
    /**
     * 回溯  +  剪枝 模板
     */
    string getHappyString(int n, int k) {
        string path;
        dfs(n, k, path);
        return cnt == k ? res : "";
    }

    void dfs(int n, int k, string& path) {
        if (cnt == k) return;  // 如果的到前K个则返回
        if (path.size() == n) {  // 如果字符串长度达到要求，更新答案并计数
            cnt++;
            res = path;
            return;
        }
        // 枚举每一个字符
        for (char c = 'a'; c <= 'c'; c++) {
            // 剪枝 如果前一个和当前值重复的话 剪枝
            if (path.size() && path.back() == c) continue;
            path.push_back(c);
            dfs(n, k, path);
            path.pop_back();
        }
    }
};