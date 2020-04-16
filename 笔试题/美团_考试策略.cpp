#include <iostream>

using namespace std;

/**
 * 小明同学在参加一场考试，考试时间2个小时。试卷上一共有n道题目，小明要在规定时间内，
 * 完成一定数量的题目。  考试中不限制试题作答顺序，对于 i 第道题目，
 * 小明有三种不同的策略可以选择:
 * (1)直接跳过这道题目，不花费时间，本题得0分。
 * (2)只做一部分题目，花费pi分钟的时间，本题可以得到ai分。
 * (3)做完整个题目，花费qi分钟的时间，本题可以得到bi分.
 * 小明想知道，他最多能得到多少分。
 *
 * 思路：动态规划 0-1背包问题的思路
 */

const int N = 100;

int dp[N][121];  // dp[i][j]在j分钟做前i道题最大的得分
int n;
int p[N], a[N], q[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> a[i] >> q[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 120; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= p[i] && j >= q[i])
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - p[i]] + a[i],
                                                 dp[i - 1][j - q[i]] + b[i]));
            else if (j >= p[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i]] + a[i]);
            else if (j >= q[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - q[i]] + b[i]);
        }
    }
    cout << dp[n][120] << endl;
}