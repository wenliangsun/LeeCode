#include <climits>
/**
 * 题目29：两数相除
 */
class LeeCode29 {
   public:
    /**
     * 思路：把所有的数字都转换成负数。因为最小的负数能比正数多保留一位
     *
     */
    int divide(int dividend, int divisor) {
        int ans = -1;
        int sign = 1;
        if (dividend > 0) {  // 转负数
            sign = ~sign + 1;
            dividend = ~dividend + 1;
        }
        if (divisor > 0) {  // 转负数
            sign = ~sign + 1;
            divisor = ~divisor + 1;
        }
        // 记录原始的被除数和除数
        int raw_dividend = dividend;
        int raw_divisor = divisor;
        if (dividend > divisor) {
            return 0;
        }
        dividend -= divisor;
        // 注意！！！ 这儿大大减少减法的次数
        while (divisor >= dividend) {
            ans = ans + ans;
            divisor += divisor;
            dividend -= divisor;
        }
        // 剩余的数再调用原始的除数来求
        int temp = ~divide(raw_dividend - divisor, raw_divisor) + 1;
        int a = ans + temp;
        // 判断溢出情况
        if (a == INT_MIN) {
            if (sign < 0) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        } else {
            if (sign > 0) {
                return ~a + 1;
            } else {
                return a;
            }
        }
    }
};