#include <iostream>

using namespace std;

/**
 * 题目：https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 *
 * 思路：分组背包问题
 */

const int N = 32010, M = 70;

int n, m;
int v[M][4], w[M][4];
int dp[M][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {  // 主件
            for (int j = 0; j < 4; j++) {
                v[i][j] += x, w[i][j] += x * y;
            }
        } else if (v[z][1] == v[z][0]) {  // 添加附件1
            v[z][1] += x, w[z][1] += x * y;
            v[z][3] += x, w[z][3] += x * y;
        } else {  // 添加附件2
            v[z][2] += x, w[z][2] += x * y;
            v[z][3] += x, w[z][3] += x * y;
        }
    }

    for (int i = 1; i <= m; i++) {      //购物的数量
        for (int j = 1; j <= n; j++) {  // 价钱
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < 4; k++) {  // 分的组数
                if (j >= v[i][k])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << dp[m][n] << endl;
}
