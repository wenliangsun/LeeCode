#include <bits/stdc++.h>

using namespace std;

/**
 * 已知深渊有N层台阶构成（1<=N<=1000)，并且每次月神仅可往上爬2的整数次幂个台阶(1、2、4、....)，
 * 请你编程告诉月神，月神有多少种方法爬出深渊
 *
 * 思路： 动态规划 dp[i] 表示爬到i的高度所有方案的集合，其值表示所有方案数
 */

typedef long long LL;

const int N = 1010, mod = 1e9 + 3;

int n;
LL dp[N];

int main() {
    int M;
    cin >> M;
    while (M--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            if (i <= 1)  // base case
                dp[i] = 1;
            else {
                LL t = 0;
                // 遍历最后一次可跳的所有方案数，并求和
                for (int j = 1; j <= i; j *= 2) {
                    t += dp[i - j];
                    if (t > mod) t = t - mod;
                }
                if (t > mod) t = t - mod;
                dp[i] = t;
            }
        }
        LL res = dp[n] > mod ? dp[n] - mod : dp[n];
        cout << res << endl;
    }
    return 0;
}