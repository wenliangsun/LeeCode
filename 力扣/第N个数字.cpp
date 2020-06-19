#include <bits/stdc++.h>

using namespace std;

/**
 * 题目400：第N个数字
 */

class Solution {
   public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        int base = 1;
        long cnt = 0;
        while (true) {
            cnt = helper(base);  //计算当前base有多少位
            if (n < cnt) break;
            n -= cnt;
            base++;
        }
        // 计算确切数字
        int num = (int)(n / base + pow(10, base - 1));
        string t = to_string(num);  // 转字符串
        return t[n % base] - '0';   // 获字符串中的数字
    }

    long helper(int base) {
        if (base == 1) return 10;
        return 9ll * pow(10, base - 1) * base;
    }
};