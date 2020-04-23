#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 最长回文子串
 */

// 中心扩展法
int helper(string s, int l, int r) {
    while (l >= 0 && r < s.size()) {
        l--, r++;
    }
    return r - l - 1;
}

int main() {
    string s;
    while (getline(cin, s)) {
        // 动态规划版本
        // vector<vector<bool>> dp(s.size() + 1,
        //                         vector<bool>(s.size() + 1, false));
        // int res = 1;
        // for (int i = 0; i < s.size(); i++) {
        //     dp[i][i] = true;
        //     for (int j = 0; j < i; j++) {
        //         dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
        //         if (dp[j][i]) {
        //             res = max(res, i - j + 1);
        //         }
        //     }
        // }
        // cout << res << endl;

        // 中心扩展法
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res = max(res, helper(s, i, i));
            res = max(res, helper(s, i, i + 1));
        }
        cout << res << endl;
    }
}