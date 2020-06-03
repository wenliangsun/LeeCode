#include <bits/stdc++.h>

using namespace std;

/**
 * 又到了丰收的季节，恰逢小易去牛牛的果园里游玩。牛牛常说他对整个果园的每个地方都了如指掌，小易不太相信，所以他想考考牛牛。
 * 在果园里有N堆苹果，每堆苹果的数量为ai，小易希望知道从左往右数第x个苹果是属于哪一堆的。
 * 牛牛觉得这个问题太简单，所以希望你来替他回答。
 *
 * 时间复杂度要求：O(nlogn)  需要二分  暴力会超时
 */

const int N = 100010;

int n, m;
int a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a[i] = a[i - 1] + t;
    };
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int l = 1, r = n;
        // 二分
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= p)
                l = mid;
            else
                r = mid - 1;
        }
        // 注意这儿的特殊处理操作
        int res = p - a[l] > 0 ? l + 1 : l;
        cout << res << endl;

        // 暴力超时  转二分
        // for (int i = 0; i < n; i++) {
        //     if (p > a[i])
        //         p -= a[i];
        //     else {
        //         cout << i + 1 << endl;
        //         break;
        //     }
        // }
    }
    return 0;
}
