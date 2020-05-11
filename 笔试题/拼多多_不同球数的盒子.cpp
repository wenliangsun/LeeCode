#include <bits/stdc++.h>

using namespace std;

/**
 * N个盒子（1~N），盒子i中有$A_i$个球，现需使每个盒中球的个数各不相同，
 * 盒子里面只能放入不可取出，问题：最少放入多少球，使每个盒子球数各不相同。
 */

typedef long long LL;

const int N = 100010;

LL a[N];
int n;

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);  // 排序
        LL res = 0;
        // 遍历数组，暴力增加
        for (int i = 1; i < n; i++) {
            // 如果当数小于等于前一个数，则当前数变为前一个数+1,并计算需要添加多少个球
            if (a[i] <= a[i - 1]) {
                res += 1LL * (a[i - 1] - a[i] + 1);
                a[i] = a[i - 1] + 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}