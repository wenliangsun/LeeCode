#include <bits/stdc++.h>

using namespace std;

/**
 * 题目190：颠倒二进制位
 * 颠倒给定的 32 位无符号整数的二进制位。
 */

class Solution {
   public:
    /**
     * 思路：对于每一位进行颠倒
     * 从右至左，对于每一位进行颠倒，通过n&1获取每一位，然后向右移动到相应的位置和之前的结果相加
     */
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, power = 31;
        while (n) {
            // 最后一位移动到对应的位置与之前的结果相加
            res += (n & 1) << power;
            // 更新最后一位
            n = n >> 1;
            power--;
        }
        return res;
    }
};