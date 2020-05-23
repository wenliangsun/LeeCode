/**
 * 题目69：x的平方根
 */
class LeeCode69 {
   public:
    /**
     * 思路：二分查找
     * 注意二分法的循环终止条件，左右边界的更新。力扣上面有个总结！！！
     * 时间复杂度：O(logN)
     * 空间复杂度：O(1)
     */
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int left = 1;
        int right = x / 2;
        while (left < right) {
            // 注意这儿的+1操作，避免死循环！！！
            long mid = left + (right - left + 1) / 2;
            long square = mid * mid;
            if (square > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return left;
    }

    /**
     * 思路：牛顿法
     * Xn+1 = (Xn+X/Xn)/2
     */
    int mySqrt2(int x) {
        long temp = x;
        while (temp * temp > x) {
            temp = (temp + x / temp) / 2;
        }
        return temp;
    }
};
