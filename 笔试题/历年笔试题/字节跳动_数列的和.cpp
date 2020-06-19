#include <bits/stdc++.h>

using namespace std;

/**
 * 数列的定义如下：数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
 *
 * 按照题目计算即可
 */

int main() {
    int n, m;
    while (cin >> n >> m) {
        double res = 0, dn = n;
        for (int i = 0; i < m; i++) {
            res += dn;
            dn = sqrt(dn);
        }
        printf("%.2f\n", res);
    }
    return 0;
}