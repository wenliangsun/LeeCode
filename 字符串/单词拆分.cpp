#include <bits/stdc++.h>

using namespace std;

// 暴力深搜
bool dfs(string s, unordered_set<string> dict, int begin) {
    if (begin == s.size()) return true;
    for (int i = begin; i < s.size(); i++) {
        if (dict.find(s.substr(begin, i - begin + 1)) != dict.end() &&
            dfs(s, dict, i + 1))
            return true;
    }
    return false;
}

// 备忘录式深搜
bool dfs2(string s, unordered_set<string> dict, int begin, vector<int>& memo) {
    if (begin == s.size()) return true;
    if (memo[begin]) return memo[begin] > 0;
    for (int i = begin; i < s.size(); i++) {
        if (dict.find(s.substr(begin, i - begin + 1)) != dict.end() &&
            dfs2(s, dict, i + 1, memo)) {
            memo[begin] = 1;
            return true;
        }
    }
    memo[begin] = -1;
    return false;
}

int main() {
    string s;
    cin >> s;
    string w;
    unordered_set<string> dict;
    while (cin >> w) {
        dict.insert(w);
    }
    // 动态规划
    vector<bool> dp(s.size() + 1,
                    false);  // 表示字符串前i个字符是否可以拆分成单词表中单词
    dp[0] = true;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << dp[s.size()] << endl;

    // 深搜
    cout << dfs(s, dict, 0) << endl;

    // 备忘录式深搜
    vector<int> memo(s.size(), 0);  // 0是未被访问  1是可以，-1是不可以
    cout << dfs2(s, dict, 0, memo) << endl;
    return 0;
}