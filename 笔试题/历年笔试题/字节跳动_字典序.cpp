#include <bits/stdc++.h>

using namespace std;

/**
 * 给定整数n和m, 将1到n的这n个整数按字典序排列之后, 求其中的第m个数。
 */

typedef long long LL;

LL n, m;

int main() {
    cin >> n >> m;
    LL idx = 1;
    m--;
    while (m) {
        LL st = idx, ed = idx + 1;
        LL num = 0;
        while (st <= n) {
            num += min(n + 1, ed) - st;
            st *= 10;
            ed *= 10;
        }
        if (num > m) {
            idx *= 10;
            m--;
        } else {
            m -= num;
            idx++;
        }
    }
    cout << idx << endl;
    return 0;
}