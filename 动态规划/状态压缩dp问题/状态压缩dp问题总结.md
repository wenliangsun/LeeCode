# 状态压缩dp问题总结

## 毕业旅行问题

小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。由于经费有限，希望能够通过合理的路线安排尽可能的省些路上的花销。给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。$1\le n \leq 20$. [毕业旅行问题](https://www.acwing.com/problem/content/733/)

输入：城市个数n，城市间的车票价钱，n行n列。<br>输出：输出一个整数，表示最小车费花销。

样例：<br>
4<br>0 2 6 5<br>2 0 4 4<br>6 4 0 2<br>5 4 2 0<br>输出：13

思路：状态压缩dp，dp[i][j] 表示经历了i所表示的城市，最终停留在j的最小花费。i是一个二进制表示的数，每一位0表示当前城市没有经过，1表示当前城市已经过。

### 参考代码

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int dp[M][N];  //表示走过了i个城市，最终停在j的最小花费
int w[N][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(dp, 0x3f, sizeof dp);  // 初始化为正无穷
    dp[1][0] = 0;  // 从0号点开始，i前面为0，最后一位是1，所以是1
    for (int i = 0; i < 1 << n; i++)  // 枚举所有方案
        for (int j = 0; j < n; j++)   // 枚举所有停的城市
            // 判断i里面第j位是否是1。只有i里面存在j，才有可能最后处于j
            if (i >> j & 1)
                for (int k = 0; k < n; k++)  // 枚举从什么地方转移过来的
                    if (i - (1 << j) >> k & 1)  // i中存在第k个地方，才可以转移
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);

    int res = 1e9;
    // 枚举从哪个城市走回原点
    for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i] + w[i][0]);
    cout << res << endl;
    return 0;
}
```