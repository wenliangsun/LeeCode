class Solution {
   public:
    /**
     * 思路：最后的零只可能是乘以10得到的，而10是有2*5得到的
     * 所以转换成求阶乘中有多少对2和5，而2是每两个出现一次，5是每五次出现一次，所以找到5肯定可以和2匹配
     * 因此就转换成求有多少个5.
     */
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
};