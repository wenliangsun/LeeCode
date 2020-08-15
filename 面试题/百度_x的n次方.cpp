#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

/**
 * 快速幂，注意正负
 */

int main() {
    int x, n;
    cin >> x >> n;
    int absn = abs(n);
    double t = x, res = 1;
    while (absn) {
        if (absn & 1) res = res * t;
        t = t * t;
        absn >>= 1;
    }
    if (n < 0)
        cout << 1 / res << endl;
    else
        cout << res << endl;
    return 0;
}