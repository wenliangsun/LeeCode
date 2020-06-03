#include <bits/stdc++.h>

using namespace std;

/**
 * 牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
 * 但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
 * 牛牛希望你能帮他计算一共有多少个可能的数对。
 */

typedef long long LL;

int main() {
    int n, k;
    while (cin >> n >> k) {
        LL res = 0;
        // 暴力，超时  时间复杂度：O(n^2)
        // for (int x = 1; x <= n; x++) {
        //     for (int y = 1; y <= n; y++) {
        //         if (x % y >= k) res++;
        //     }
        // }

        // k为0 的情况
        if (k == 0) {
            cout << (LL)n * n << endl;
            continue;
        } else {
            // 要想余数大于等于K，y必须大于K,从K+1开始遍历 时间复杂度：O(n)
            for (int y = k + 1; y <= n; y++) {
                // 因为余数每隔y个会循环，所以找有多少的完整的循环，每一个循环中余数都是0~y-1,大于k的余数有
                // y-k
                res += n / y * (y - k);
                // 如果不够完整的循环，但是最后的余数大于k时，统计其中余数大于等于k的情况
                if (n % y >= k) {
                    res += n % y - k + 1;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}