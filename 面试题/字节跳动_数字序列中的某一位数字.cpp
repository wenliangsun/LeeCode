#include <bits/stdc++.h>

using namespace std;

/**
 * 数字以0123456789101112131415…的格式序列化到一个字符序列中。
 * 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
 * 请写一个函数，求任意第n位对应的数字。
 * 数字序列中某一位的数字:https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
 */

typedef long long LL;

LL count(int base) { // 统计base位数字的个数
    if (base == 1) return 10;
    return 9ll * pow(10, base - 1) * base;
}

int findNthDigit(int n) {
    if (n < 10) return n;
    int base = 1;
    while (true) {
        LL cnt = count(base);
        if (n < cnt) break;
        n -= cnt;
        base++;
    }
    int nums = (int)(n / base + pow(10, base - 1)); // 计算当前数字
    string t = to_string(nums);
    int res = t[n % base] - '0'; // 计算当前数字中的某一位
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = findNthDigit(n);
    cout << res << endl;
}