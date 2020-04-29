#include <iostream>

using namespace std;

/**
 * 有n个牢房，编号为1~n,每个牢房中都包含一个，每个人都可以在1~m中选择一个数字，
 * 如果有相邻牢房选择的数字相同，则会发生冲突。
 * 求发生冲突的情况有多少种？结果取mod100003.
 *
 * 输入m，n
 * 输出发生冲突的情况
 *
 * 思路：数学推导，所有情形数-任意相邻房间数不同的情形，即m^n - m* (m-1)^(n-1)
 * 考察点：快速幂算法：有模板！！！
 */

const int mod = 100003;
typedef long long LL;

// 快速幂模板 m^k%p 时间复杂度O(logk)
int qmi(int m, int k, int p) {
    int res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main() {
    LL m, n;
    while (cin >> m >> n) {
        int x1 = qmi(m, n, mod);
        int x2 = m * qmi(m - 1, n - 1, mod);
        cout << x1 - x2 << endl;
    }
}