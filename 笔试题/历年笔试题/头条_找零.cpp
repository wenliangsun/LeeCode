#include <iostream>

using namespace std;

/**
 * 头条题目：商家有1 4 16
 * 64的硬币，小明有1024的纸币，小明买了价值在1-1024之间的货物。问店家最少要找多少个硬币
 */

int main() {
    int n;
    cin >> n;
    n = 1024 - n;
    int coins[4] = {64, 16, 4, 1};
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += n / coins[i];
        n %= coins[i];
    }
    cout << res << endl;
}