#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 求抛物线 $y^2 = 2Ax$ 和直线 $y = Bx + C$ 所围成的面积.
 * 输入：A B C
 * 输出：面积
 *
 * 思路：
 * 联合两个方程 先求解交点的y坐标：y = (A+-sqrt(A^2-2ABC))/ B
 * 然后定积分求解 直线方程-抛物线方程
 */

int f(int A, int B, int C) {
    int delta = pow(A, 2) - 2 * A * B * C;
    if (delta < 0) return 0;
    double y1 = (A - sqrt(delta)) / B, y2 = (A + sqrt(delta)) / B;
    double x2 = pow(y2, 2) / (2 * B) - C / B * y2 - pow(y2, 3) / (6 * A);
    double x1 = pow(y1, 2) / (2 * B) - C / B * y1 - pow(y1, 3) / (6 * A);
    return x2 - x1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        double res = f(A, B, C);
        cout << res << endl;
    }
    return 0;
}
