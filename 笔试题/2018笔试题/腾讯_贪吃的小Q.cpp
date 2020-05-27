#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
 * 小Q决定每天吃的巧克力数量不少于前一天吃的一半，
 * 但是他又不想在父母回来之前的某一天没有巧克力吃，
 * 请问他第一天最多能吃多少块巧克力
 *
 * 二分法
 */

bool check(int mid, int m, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mid;
        mid = (mid + 1) >> 1;
    }
    return sum <= m;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 1) {
            cout << m << endl;
            continue;
        } else {
            int l = 1, r = m;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (check(mid, m, n))
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}