#include <iostream>
#include <vector>

using namespace std;

/**
 * 腾讯题目：小Q打算穿越怪兽谷，他不会打怪，但是他有钱。他知道，只要给怪兽一定的金币，
 * 怪兽就会一直护送着他出谷。在谷中，他会依次遇见N只怪兽，
 * 每只怪兽都有自己的武力值和要“贿赂”它所需的金币数。
 * 如果小Q没有“贿赂”某只怪兽，而这只怪兽“武力值”又大于护送他的怪兽武力之和，
 * 这只怪兽就会攻击他。小Q想知道，要想成功穿越怪兽谷而不被攻击，他最少要准备多少金币
 *
 * 思路:动态规划
 */

const int N = 55, M = N * 2;

int main() {
    int n;
    cin >> n;
    vector<long long> damage(N, 0);
    vector<int> cost(N, 0);
    for (int i = 0; i < n; i++) {
        cin >> damage[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    // dp[i][j] 表示当遇到第i只怪兽花费了j的金币，所获得的最大武力值
    // 初始化为不和法-1
    vector<vector<long long>> dp(N, vector<long long>(M, -1));
    dp[0][0] = 0;  // base case
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 2; j++) {
            // 对于当前怪兽，有两种选择，要么买，要么不买
            if (j + 1 >= cost[i] && dp[i][j + 1 - cost[i]] != -1)
                // 如果买了，金币减了，武力值增加了，注意这儿的条件
                dp[i + 1][j + 1] = dp[i][j + 1 - cost[i]] + damage[i];
            if (dp[i][j + 1] >= damage[i])
                // 取买了和没买中的伤害值最大的情况，注意条件限制
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }
    int res = 0;
    // 寻找第一个合法的金币数即为答案
    for (int i = 0; i <= 2 * n; i++) {
        if (dp[n][i] != -1) {
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}