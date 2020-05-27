#include <iostream>

using namespace std;

/**
 * 小Q定义了一种数列称为翻转数列:
 * 给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4...,
 * 每隔m个符号翻转一次, 最初符号为'-';。 例如n = 8, m = 2, 数列就是: -1, -2, +3,
 * +4, -5, -6, +7, +8. 而n = 4, m = 1, 数列就是: -1, +2, -3, + 4.
 * 小Q现在希望你能帮他算算前n项和为多少。
 *
 * 推导：f(n) = f(n-1)-2*m*m 负数的时候 ，f(n) = f(n-1)+2*m*m 正数的时候
 */

typedef long long LL;

void helper(LL sum, LL n, LL m, LL& res) {
    LL tmp = sum;
    res += tmp;
    if (sum < 0) {
        for (int i = 2; i <= n; i++) {
            tmp = tmp - 2 * m * m;
            res += tmp;
        }
    } else {
        for (int i = 2; i <= n; i++) {
            tmp = tmp + 2 * m * m;
            res += tmp;
        }
    }
}

int main() {
    LL n, m;
    while (cin >> n >> m) {
        LL pnum = 0, nnum = 0;
        for (LL i = 1; i <= m; i++) {
            nnum += -i;
        }
        for (LL i = m + 1; i <= 2 * m; i++) {
            pnum += i;
        }
        LL res = 0;
        helper(nnum, n % m ? n / (2 * m) + 1 : n / (2 * m), m, res);
        helper(pnum, n / (2 * m), m, res);
        cout << res << endl;
    }
    return 0;
}