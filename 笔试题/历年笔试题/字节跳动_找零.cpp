#include <bits/stdc++.h>

using namespace std;

/**
 * Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。
 * 现在小Y使用1024元的纸币购买了一件价值为N
 * (0 < N \le 1024)N(0<N≤1024)的商品，请问最少他会收到多少硬币？
 * 
 * 思路：从最大面值的硬币开始凑
 */

int main() {
    int n;
    cin >> n;
    n = 1024 - n;
    int res = 0;
    int coins[4] = {64, 16, 4, 1};
    for (int i = 0; i < 4; i++) {
        res += n / coins[i];
        n = n % coins[i];
    }
    cout << res << endl;
    return 0;
}