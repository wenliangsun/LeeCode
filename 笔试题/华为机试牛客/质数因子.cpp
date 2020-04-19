#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子
 * （如180的质因子为2 2 3 3 5 ）最后一个数后面也要有空格
 */

int main() {
    long n;
    cin >> n;
    for (long i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            cout << i << ' ';
            n /= i;
        }
        if (n == 1) break;
    }
    if (n > 1) {
        cout << n << ' ';
    }
}