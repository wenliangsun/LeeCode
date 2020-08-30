#include <bits/stdc++.h>

using namespace std;

/**
 * 数字序列中某一位的数字
 */

class Solution {
   public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        int base = 1;
        long cnt = 0;  // 计算当前base有多少位
        while (true) {
            cnt = helper(base);
            if (n < cnt) break;
            n -= cnt;
            base++;
        }
        // 找到确切的数字
        int num = (int)(n / base + pow(10, base - 1));
        string t = to_string(num);  //转换成字符串
        return t[n % base] - '0';   // 找字符串中对应的位置的数字
    }

    long helper(int base) {
        if (base == 1) return 10;
        return 9ll * pow(10, base - 1) * base;
    }
};