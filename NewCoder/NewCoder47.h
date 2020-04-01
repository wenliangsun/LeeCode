
/**
 * 题目47：求1+2+3+...+n。要求不能使用乘除法、for、while、if、else、switch、case等关键字
 */
class NewCoder47 {
   public:
    /**
     * 思路：利用逻辑与的短路特性实现递归终止，
     * (1) 当n==0，(n > 0) && ((sum += Sum_Solution01(n - 1)) > 0)
     * 只执行前面的条件，为false，递归终止； (2) 当n>0时，执行sum +=
     * Sum_Solution01(n - 1) ，实现递归计算。
     */
    int Sum_Solution01(int n) {
        int sum = n;
        bool ans = (n > 0) && ((sum += Sum_Solution01(n - 1)) > 0);
        return sum;
    }
};