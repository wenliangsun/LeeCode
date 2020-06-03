#include <bits/stdc++.h>

using namespace std;

/**
 * 数位之积
 * 现给定任意正整数 n，请寻找并输出最小的正整数 m（m>9），使得 m
 * 的各位（个位、十位、百位 ... ...）之乘积等于n，若不存在则输出 -1。
 */

int main() {
    int n;
    cin >> n;
    int res = 0, base = 1;
    // 从大到小尝试，然后反过来求得答案数字
    for (int i = 9; i > 1; i--) {
        while (!(n % i)) {
            res += i * base;
            base *= 10;
            n /= i;
        }
    }
    if (n > 1)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}