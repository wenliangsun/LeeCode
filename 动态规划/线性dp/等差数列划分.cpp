#include <bits/stdc++.h>

using namespace std;

/**
 * 等差数列划分
 */

class Solution {
   public:
    /**
     * 思路：暴力法
     * 先计算相邻两个元素之间的差，然后枚举区间起点和枚举区间终点，判断区间内是不是等差数列即可
     * 时间复杂度：O(n^3)
     */
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0, n = A.size();
        for (int s = 0; s < n - 2; s++) {      // 枚举起点
            int d = A[s + 1] - A[s];           // 计算等差
            for (int e = s + 2; e < n; e++) {  // 枚举终点
                int k = 0;
                for (k = s + 1; k <= e; k++) {  // 判断区间是不是等差数列
                    if (A[k] - A[k - 1] != d) break;
                }
                if (k > e) cnt++;  // 区间是等差数列的话，计数+1
            }
        }
        return cnt;
    }

    /**
     * 优化的暴力
     * 时间复杂度：O(n^2)
     */
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0, n = A.size();
        for (int s = 0; s < n - 2; s++) {  // 枚举区间起点
            int d = A[s + 1] - A[s];
            for (int e = s + 2; e < n; e++) {  // 枚举区间终点
                if (A[e] - A[e - 1] == d)      // 判断是否等差
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }

    /**
     * 动态规划
     * 状态表示：dp[i]表示以i结尾的等差数列的子数组个数
     * 状态计算：dp[i] = 1 + dp[i-1]
     */
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        vector<int> dp(A.size());
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = 1 + dp[i - 1];
                sum += dp[i];
            }
        }
        return sum;
    }

    /**
     * 状态压缩
     */
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), sum = 0, dp = 0;
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = 1 + dp;
                sum += dp;
            } else
                dp = 0;
        }
        return sum;
    }
};