#include <iostream>

using namespace std;

/**
 * 题目：游泳池的最大容量为m，进水的速度的m1，每隔t1分钟进水管会切换状态，如由关变开，
 * 或者开变关；出水的速度为m2，每隔t2分钟同样会切换状态。初始时进水管和出水管均为开,
 * 水池为空，问t分钟后游泳池的水量。
 * 第一行为测试用例的数量，第二行开始分别对应题目的m，t，m1，t1，m2， t2
 *
 * 注意：边界条件，如泳池空了，或者泳池满了
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, t, m1, t1, m2, t2;
        cin >> m >> t >> m1 >> t1 >> m2 >> t2;
        int res = 0;
        bool in = false, out = false;
        for (int i = 0; i < t; i++) {
            // 状态转换
            if (i % t1 == 0) in = !in;
            if (i % t2 == 0) out = !out;
            // 同时打开
            if (in && out) {
                res = max(0, res + (m1 - m2));
                res = min(res, m);
                // 打开进水
            } else if (in) {
                res += m1;
                res = min(res, m);
                // 打开出水
            } else if (out) {
                res -= m2;
                res = max(0, res);
            }
        }
        cout << res << endl;
    }
}