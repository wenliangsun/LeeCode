#include <bits/stdc++.h>

using namespace std;

/**
 * 给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，
 * 大锤的小队有多少种埋伏选择。
 * 注意：1. 两个特工不能埋伏在同一地点
 * 2. 三个特工是等价的：即同样的位置组合(A, B, C)只算一种埋伏方法，不能因“特工之间互换位置”而重复使用.
 * 
 * 枚举满足的区间，然后求组合数。
 */

const int N = 1000010, mod = 99997867;

typedef long long LL;

int n, d;

//  求组合数，从n中选两个数
LL C(LL n) { return (n - 1) * n / 2; }

int main() {
    cin >> n >> d;
    vector<int> a(n);
    LL res = 0;
    for (int i = 0, j = 0; j < n; j++) {
        cin >> a[j];
        // 固定终点j，然后寻找满足条件的起点的最小值
        while (j >= 2 && a[j] - a[i] > d) i++;
        // 从起点到终点区间中选择两个数，因为终点已经确定。
        res += C(j - i);
        if (res > mod) res -= mod;
    }
    cout << res % mod << endl;
    return 0;
}