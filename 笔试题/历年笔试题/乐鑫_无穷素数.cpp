#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

/**
 * 判断一个数是否是素数
 */
bool isPrime(LL n) {
    for (LL i = 2; i * i <= n; i++) {
        if (!(n % i)) return false;
    }
    return true;
}

int main() {
    int ai;
    cin >> ai;
    LL sum = 1;
    int n = 2;
    while (ai + 1) {
        // 寻找素数
        while (!isPrime(n)) n++;
        sum *= n;  // 累乘
        n++;       // 注意这儿需要寻找下一个素数
        ai--;
    }
    sum += 1;
    if (isPrime(sum))
        cout << sum << " is a prime" << endl;
    else
        cout << sum << " is not a prime" << endl;
    return 0;
}