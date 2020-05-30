#include <algorithm>

using namespace std;

/**
 * 题目67：剪绳子
 *
 * 动态规划遵循一套固定的流程：递归暴力解法 --> 带备忘录的递归解法 -->
 * 非递归的动态规划解法
 *
 */
class NewCoder67 {
   public:
    /**
     * 暴力递归法
     * 公式： F(n) = max(i*(n-i),i*F(n-i))
     * 即每次可以剪成两段，剩下的一段可以剪，也可以不剪
     * 时间复杂度O(n^2)
     * 空间复杂度O(n^2)
     */
    int cutRope01(int number) {
        if (number == 2) {
            return 1;
        }
        int res = -1;
        for (int i = 1; i <= number; i++) {
            res = max(res, i * (number - i));
            res = max(res, i * cutRope01(number - i));
        }
        return res;
    }

    /**
     * 带有备忘录的递归法，自顶至下
     * 时间复杂度O(n^2)
     * 空间复杂度O(n)
     */
    int cutRope02(int number) {
        int temp[number + 1];                   // 记录数组
        for (int i = 0; i < number + 1; i++) {  // 初始化为-1
            temp[i] = -1;
        }
        return cutRope02Core(number, temp);
    }

    /**
     * 自底向上，动态规划法
     */
    int cutRope03(int number) {
        int temp[number + 1];                   // 记录数组
        for (int i = 0; i < number + 1; i++) {  // 初始化为-1
            temp[i] = -1;
        }
        temp[2] = 1;  // 记录特征值
        int res = -1;
        for (int i = 3; i <= number; i++) {  // 表示当前绳子的长度
            for (int j = 1; j <= i; j++) {  // 给定绳子的长度下，最优的解
                res = max(res, j * (i - j));
                res = max(res, j * temp[i - j]);
            }
            temp[i] = res;  // 记录当前绳子长度下的最优解
        }
        return temp[number];  // 饭后记录的最优解
    }

   private:
    int cutRope02Core(int number, int* temp) {
        if (number == 2) {
            return 1;
        }
        if (temp[number] >= 0) {
            return temp[number];
        }
        int res = -1;
        for (int i = 1; i <= number; i++) {
            res = max(res, i * (number - i));
            res = max(res, i * cutRope02Core(number - i, temp));
        }
        return res;
    }
};