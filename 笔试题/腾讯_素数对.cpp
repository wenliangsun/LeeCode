#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。
 * 输入值小于1000。
 */

/**
 * 生成从1到n的素数
 */
vector<int> countPrime(int n) {
    vector<bool> tmp(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (tmp[i]) {
            for (int j = i * i; j <= n; j += i) {
                tmp[j] = false;
            }
        }
    }
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (tmp[i]) res.push_back(i);
        // 这儿是为了解决 类似10 可以由5和5得到的情况，即把5添加两次
        if (i == n / 2 && tmp[n / 2]) res.push_back(i);
    }
    return res;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> primes = countPrime(n);
        int l = 0, r = primes.size() - 1;
        int res = 0;
        // 双指针！！！
        while (l < r) {
            int sum = primes[l] + primes[r];
            if (sum == n) {
                res++;
                l++, r--;
            } else if (sum > n) {
                r--;
            } else {
                l++;
            }
        }
        cout << res << endl;
    }
    return 0;
}