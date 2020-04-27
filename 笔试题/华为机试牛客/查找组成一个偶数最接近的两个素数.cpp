#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
 * 本题目要求输出组成指定偶数的两个素数差值最小的素数对
 */

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        int x, y;
        for (int i = 1; i <= n / 2; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                x = i, y = n - i;
            }
        }
        cout << x << endl << y << endl;
    }
    return 0;
}