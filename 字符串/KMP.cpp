#include <bits/stdc++.h>

using namespace std;

/**
 * 时间复杂度：O(M+N)
 */
int search(string& s, string& p) {
    int m = p.size(), n = s.size();
    vector<int> fail(m, -1);
    // 构建fail数组
    for (int i = 1; i < m; i++) {
        int j = fail[i - 1];
        while (j != -1 && p[j + 1] != p[i]) j = fail[j];
        if (p[j + 1] == p[i]) fail[i] = j + 1;
    }

    int match = -1;
    // 匹配
    for (int i = 0; i < n; i++) {
        while (match != -1 && p[match + 1] != s[i])
            match = fail[match];     // 如果不匹配，往前调
        if (p[match + 1] == s[i]) {  // 如果匹配
            match++;
            if (match == m - 1) {
                cout << i - match << endl;
                return true;
            }
        }
    }
    return false;
}

/**
 * 动态规划版
 * 状态机
 */
int search2(string s, string p) {
    int M = p.size(), N = s.size();
    // 动态数组  dp[状态][字符] = 下一个状态
    vector<vector<int>> dp(M, vector<int>(256, 0));
    // base case
    dp[0][p[0]] = 1;
    // 影子状态初始化为0
    int X = 0;
    // 利用模式串构建状态转移图
    for (int j = 1; j < M; j++) {
        for (int c = 0; c < 256; c++) {
            if (p[j] == c)
                dp[j][c] = j + 1;
            else
                dp[j][c] = dp[X][c];
        }
        X = dp[X][p[j]];
    }
    int j = 0;  // 记录状态 模式初始状态为0
    // 在字符串中匹配
    for (int i = 0; i < N; i++) {
        j = dp[j][s[i]];
        // 如果状态到达模式串尾部，说明匹配成功
        if (j == M) return i - M + 1;
    }
    return -1;
}

int main() {
    string s = "xyxyyxxyx", p = "yyx";
    cout << search(s, p) << endl;
    return 0;
}