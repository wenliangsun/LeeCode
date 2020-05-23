#include <bits/stdc++.h>

using namespace std;

/**
 * 题目93：复原IP地址
 */
class LeeCode93 {
   public:
    /**
     * 思路：回溯发+剪枝
     */

    vector<string> res;

    bool isValid(string s) {
        if (s.empty() || (s.size() && s[0] == '0')) return false;
        int val = stoi(s);
        if (val >= 0 && val <= 255) return true;
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 4, "");
        return res;
    }

    /**
     * idx 记录字符串的位置，residue记录ip的块数，path记录路径
     */
    void dfs(string s, int idx, int residue, string path) {
        if (idx == s.size()) {
            if (residue == 0) {
                path.pop_back();
                res.push_back(path);
            }
            return;
        }
        // 计算当前块
        for (int i = idx; i < idx + 3; i++) {
            // 如果超出界线 剪枝
            if (i >= s.size()) break;
            // 如果剩余的超出可能的范围，则为当前块继续添加
            if (residue * 3 < s.size() - i) continue;
            // 如果这个块的地址是合法的，则递归  否则剪枝
            if (isValid(s.substr(idx, i - idx + 1))) {
                dfs(s, i + 1, residue - 1,
                    path + s.substr(idx, i - idx + 1) + '.');
            }
        }
    }
};