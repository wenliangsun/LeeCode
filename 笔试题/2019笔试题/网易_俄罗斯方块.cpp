#include <bits/stdc++.h>

using namespace std;

/**
 * 荧幕上一共有 n 列，每次都会有一个 1 x 1
 * 的方块随机落下，在同一列中，后落下的方块会叠在先前的方块之上，当一整行方块都被占满时，这一行会被消去，并得到1分。
 * 有一天，小易又开了一局游戏，当玩到第 m
 * 个方块落下时他觉得太无聊就关掉了，小易希望你告诉他这局游戏他获得的分数。
 *
 * 题目链接：https://www.nowcoder.com/practice/9407e24a70b04fedba4ab3bd3ae29704?tpId=98&tqId=32832&tPage=1&rp=1&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking
 */

const int N = 1010;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        g[x]++;  // 统计每一列中出现的次数
    }
    int res = INT_MAX;
    // 找出现次数最少的就是答案
    for (int i = 1; i <= n; i++) {
        res = min(res, g[i]);
    }
    cout << res << endl;

    return 0;
}