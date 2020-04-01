
/**
 * 题目48：不用加减乘除做加法
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
 */
class NewCoder48 {
   public:
    /**
     * 思路：考虑采用位运算来做加法，通过实验发现，位运算做加法和正常加法一样，
     * 都是先不考虑进位做加法，再把进位的结果加上去。
     * 发现位运算的不进位加法等价于两个数异或的结果，
     * 位运算的进位只有两个数对应位全是1时才进位，可以通过两个数的与操作然后左移一位得到。
     * (1) 两数字做异或运算得到不进位的和；
     * (2) 两个数字做与运算然后左移一位得到进位的结果。
     * (3) 将上面两个结果相加，直到没有进位停止。
     *
     */
    int Add(int num1, int num2) {
        int sum;
        int carry;
        sum = num1 ^ num2;           // 计算不进位的和
        carry = (num1 & num2) << 1;  // 计算进位
        num1 = sum;
        num2 = carry;
        while (num2 != 0) {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return sum;
    }

    /**
     * 相关问题：不用新的变量，交换两个变量的值，有两种方法
     * (1) 基于加减法；
     * (2) 基于异或运算
     */
    void swap1(int a, int b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    void swap2(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};