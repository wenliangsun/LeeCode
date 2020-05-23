#include <bits/stdc++.h>

using namespace std;

/**
 * 平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i],
 * y2[i])。
 * 如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。
 * 请你计算出平面内重叠矩形数量最多的地方,有多少个矩形相互重叠。
 */

const int N = 55;

int ldx[N], ldy[N], rbx[N], rby[N];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> ldx[i];
        for (int i = 0; i < n; i++) cin >> ldy[i];
        for (int i = 0; i < n; i++) cin >> rbx[i];
        for (int i = 0; i < n; i++) cin >> rby[i];
        int res = 0;
        // 无论何种情况，重叠区域也是四条边组成。而且是取自与n的矩形中的四条。所以遍历边的交点即可.
        for (auto x : ldx) {
            for (auto y : ldy) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (x >= ldx[i] && x < rbx[i] && y >= ldy[i] &&
                        y < rby[i]) {
                        cnt++;
                    }
                    res = max(res, cnt);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}