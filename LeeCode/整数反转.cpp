#include <climits>
/**
 * 题目7：整数反转
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 */
class LeeCode07 {
   public:
    /**
     * 考虑溢出的情况
     * 如果直接考虑 res = res*10+temp,会导致溢出，
     * 我们需要在计算这个之前判断下一步操作是否会溢出。
     * 1. 判断 res = res*10 + temp > INT_MAX 溢出情况
     *     (1) 当 res> INT_MAX/10 且还有temp需要添加时，一定会溢出；
     *     (2) 当 res = INT_MAX/10,且temp>7时，一定会溢出，因为7是2^31-1的最后一位数
     * 2. 判断 res = res*10 + temp <INT_MIN 溢出情况
     *     (1) 当 res<INT_MIN/10,且还有temp添加时，一定会溢出；
     *     (2) 当 res= INT_MIN / 10,且temp<-8 时，一定会溢出，8是-2^31的最后一位数。
     * 
     */
    int reverse(int x) {
        int res = 0;
        while (x) {
            int temp = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8)) {
                return 0;
            }
            res = res * 10 + temp;
        }
        return res;
    }
};