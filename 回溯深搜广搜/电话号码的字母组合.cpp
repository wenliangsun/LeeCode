#include <bits/stdc++.h>

using namespace std;

/**
 * 题目17：电话号码的字母组合
 */

class Solution {
   public:
    vector<string> res;
    map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                           {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        string path;
        dfs(digits, 0, path);
        return res;
    }

    void dfs(string& digits, int idx, string& path) {
        if (idx == digits.size()) {
            res.push_back(path);
            return;
        }
        string s = m[digits[idx]];
        for (auto c : s) {
            path.push_back(c);
            dfs(digits, idx + 1, path);
            path.pop_back();
        }
    }
};