#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 腾讯题目：小Q去商场购物，经常会遇到找零的问题。
 * 小Q现在手上有n种不同面值的硬币，每种面值的硬币都有无限多个。
 * 为了方便购物，小Q希望带尽量少的硬币，并且要能组合出1到m之间（包含1和m）的所有面值。
 *
 * 思路：先对硬币排序，如果第一个硬币不是1的话，凑不成返回-1，然后优先选择较大的硬币
 *  一个区间一个区间凑，ka[i]+s>=a[i+1]-1  其中s是用a[i]时凑的长度，求k
 * 上取整！！！ 上取整技巧 a除以b的 上取整为 (a+b-1)/b  ！！！
 */

const int N = 110;
int n, m;
int a[N];

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 对硬币排序
    sort(a, a + n);
    if (a[0] != 1) {
        puts("-1");
    } else {
        // 把大于m的硬币丢掉，用不到
        while (n > 0 && a[n - 1] > m) {
            n--;
        }
        // 注意这儿设置，因为每次都是凑到a[i+1]-1,可以使得a[i+1]-1=m,
        //推出a[i+1] = m+1;
        a[n] = m + 1;
        int res = 0;
        for (int i = 0, s = 0; i < n; i++) {
            // 根据公式计算k值
            int k = (a[i + 1] - 1 - s + a[i] - 1) / a[i];
            res += k;       // 更新答案
            s += k * a[i];  // 更新可以凑的长度
        }
        cout << res << endl;
    }
}