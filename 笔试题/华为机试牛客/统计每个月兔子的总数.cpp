#include <iostream>

using namespace std;

/**
 * 有一只兔子，从出生后第3个月起每个月都生一只兔子，
 * 小兔子长到第三个月后每个月又生一只兔子，
 * 假如兔子都不死，问每个月的兔子总数为多少？
 *
 * 思路：f(n)=f(n-1)+f(n-2) f(n-1)表示上个月的兔子，f(n-2)表示满足三个月大的兔子
 */

int main() {
    int n;
    while (cin >> n) {
        int a = 1, b = 1, res = 0;
        for (int i = 3; i <= n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        cout << res << endl;
    }
}