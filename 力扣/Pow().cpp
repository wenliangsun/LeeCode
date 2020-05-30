/**
 * 题目50： Pow(x,n)
 */
class LeeCode50 {
   public:
    double myPow(double x, int n) {
        long long longN = n;
        return myPow(x, longN);
    }

    /**
     * 暴力相乘
     * 时间复杂度：O(n)
     */
    double myPow2(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double res = 1;
        long long absn = n > 0 ? n : -n;
        for (long long i = 0; i < n; i++) {
            res *= x;
        }
        return n > 0 ? res : 1 / res;
    }

    /**
     * 快速幂算法(循环)
     * 时间复杂度：O(logn)
     */
    double myPow3(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        double res = 1;
        double temp = x;
        long long absn = n > 0 ? n : -n;
        for (long long i = 0; i < absn / 2; i++) {
            if (i & 1 == 1) {
                res *= temp;
            }
            temp *= temp;
        }
        return n > 0 ? res : 1 / res;
    }

   private:
    /**
     * 快速幂算法(递归)
     * 时间复杂度：O(logn)
     */
    double myPow(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        long long absn = n > 0 ? n : -n;
        double res = myPow(x, absn >> 1);
        res *= res;
        if (absn & 1 == 1) {
            res *= x;
        }
        return n > 0 ? res : 1 / res;
    }
};