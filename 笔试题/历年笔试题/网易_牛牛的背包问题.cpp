#include <bits/stdc++.h>

using namespace std;

/**
 * 牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食,
 * 牛牛的背包容量为w。 牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
 * 牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
 *
 * 思路：此类背包问题分两种
 * 一种是当物品个数n较少，但是背包大小m比较大时采用指数级的枚举搜索，复杂度为O(2^n)
 * 另一种是当背包比较小的时候采用动态规划O(nm)
 */

typedef long long LL;

const int N = 35;

LL res = 0;
LL w;
int n;
LL v[N];

void dfs(int idx, LL sum) {
    res++;
    if (idx == n) return;
    for (int i = idx; i < n; i++) {
        if (sum + v[i] <= w) dfs(i + 1, sum + v[i]);
    }
}

int main() {
    cin >> n >> w;
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];  // 计算物体的总体积
    }
    // 如果总体积小于背包容量，则方案数为2^n
    if (sum <= w) {
        res = 1 << n;
        // 否则 深搜
    } else {
        dfs(0, 0);
    }
    cout << res << endl;
    return 0;
}