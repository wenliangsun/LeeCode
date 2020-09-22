#include <bits/stdc++.h>

using namespace std;

/**
 * 字典序中的第k小数字
 */

typedef long long LL;

int minKnum(int n, int k) {
    int cur = 1;
    k--;
    while (k > 0) {
        LL a = cur, b = cur + 1;
        LL sum = 0;
        while (a <= n) {
            sum += min(n + 1ll, b) - a;
            a *= 10;
            b *= 10;
        }
        if (sum <= k) {
            k -= sum;
            cur++;
        } else {
            cur *= 10;
            k--;
        }
    }
    return cur;
}

int main() {
    int res = minKnum(13, 2);
    cout << res << endl;
}