#include <bits/stdc++.h>

using namespace std;

/**
 * 在没有任何数学库函数的情况下，求一个数 m 开 n 次方的结果。
 * 
 * 二分
 */

double mypow(double x, int n) {
    double res = 1;
    double t = x;
    while (n) {
        if (n & 1) res *= t;
        t *= t;
        n >>= 1;
    }
    return res;
}

int main() {
    double m;
    int n;
    cin >> m >> n;
    double l = 0, r = m;
    double mid;
    while (r - l > 1e-14) {
        mid = l + (r - l) / 2;
        if (mypow(mid, n) > m)
            r = mid;
        else
            l = mid;
    }
    printf("%.12f\n", mid);
    return 0;
}