#include <bits/stdc++.h>

using namespace std;

/**
 * 小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
 * 并且小Q对于能否被3整除这个性质很感兴趣。
 * 小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
 */

typedef long long LL;

int main() {
    int l, r;
    while (cin >> l >> r) {
        LL tmp = 0;
        for (int i = 1; i < l; i++) tmp += i;
        LL res = 0;
        for (int i = l; i <= r; i++) {
            tmp += i;
            if (!(tmp % 3)) res++;
        }
        cout << res << endl;
    }
    return 0;
}