#include <iostream>

using namespace std;

/**
 * 有m根绳子，长短不一，现在要剪成M根等长的绳子，问能完成的最大绳子长度
 *
 * 思路：二分法 模板
 */

const int N = 200010;
int n, m;
int a[N];

// 判断是否能够完成
bool check(int mid) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] / mid;
        if (s > m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double left = 0;
    double right = 1e9;
    while (right - left > 1e-4) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.2f\n", right);
}