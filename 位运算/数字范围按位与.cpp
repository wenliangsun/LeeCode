#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 对所有数字执行按位与运算的结果是所有对应二进制字符串的公共前缀再用零补上后面的剩余位。
     * 找位表示的公共前缀就可以
     * 时间复杂度：O(logn)
     * 空间复杂度：O(1)
     */
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            cnt++;
        }
        return m << cnt;
    }
};