#include <iostream>
#include <vector>

using namespace std;

/**
 * 一条直线上等距离放置了n台路由器。路由器自左向右从1到n编号。
 * 第i台路由器到第j台路由器的距离为| i-j |。
 * 每台路由器都有自己的信号强度，第i台路由器的信号强度为ai。
 * 所有与第i台路由器距离不超过ai的路由器可以收到第i台路由器的信号
 * （注意，每台路由器都能收到自己的信号）。
 * 问一共有多少台路由器可以收到至少k台不同路由器的信号。
 *
 * 思路：先计算每个路由器可以覆盖的范围，然后统计每个位置覆盖路由器的次数，即重叠区间的个数
 */

const int N = 100010;

int a[N];
int b[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int l = max(0, i - a[i]);
        int r = min(n - 1, i + a[i]);
        b[l]++;
        b[r + 1]--;
        // for (int i = l; i <= r; i++) {
        //     b[i]++;
        // }
    }

    int res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
        if (sum >= k) {
            res++;
        }
    }
    cout << res << endl;
}