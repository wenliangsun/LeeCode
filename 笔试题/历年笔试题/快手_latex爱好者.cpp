#include <bits/stdc++.h>

using namespace std;

/**
 * 已知iPhone屏幕的高为H，宽为W，若字体大小为S(假设为方形），则一行可放W/S(取整数部分）个文字，一屏最多可放H/S(取整数部分)行文字。
 * 已知一篇paper有N个段落，每个段落的文字数目由a1,a2,a3,....,an表示，
 * 月神希望排版的页数不多于P页（一屏显示一页），那么月神最多可使用多大的字体呢？
 *
 * 典型的二分法问题  套模板！！！
 */

const int N = 1000010;

int a[N];
int n, p, h, w;

// 核心在于如何定义check函数
bool check(int m) {
    int r = h / m, c = w / m;
    int rows = 0;
    for (int i = 0; i < n; i++) {
        int t = a[i];
        while (t > 0) {
            t -= c;
            rows++;
        }
    }
    int tp = 0;
    while (rows > 0) {
        rows -= r;
        tp++;
    }
    return tp <= p;
}

int main() {
    while (cin >> n >> p >> h >> w) {
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 1, r = min(h, w);
        // 二分法的模板
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }

    return 0;
}