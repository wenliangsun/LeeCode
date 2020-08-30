#include <bits/stdc++.h>

using namespace std;

/**
 * 一条直线上等距离放置了n台路由器。路由器自左向右从1到n编号。第i台路由器到第j台路由器的距离为|i-j |。 
 * 每台路由器都有自己的信号强度，第i台路由器的信号强度为ai。
 * 所有与第i台路由器距离不超过ai的路由器可以收到第i台路由器的信号（注意，每台路由器都能收到自己的信号）。
 * 问一共有多少台路由器可以收到至少k台不同路由器的信号。
 */

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tmp(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int l = max(0, i - x);
        int r = min(n - 1, i + x);
        tmp[l]++;
        tmp[r + 1]--;
    }
    int res = 0, t = 0;
    for (int i = 0; i < n; i++) {
        t += tmp[i];
        if (t >= k) res++;
    }
    cout << res << endl;
    return 0;
}