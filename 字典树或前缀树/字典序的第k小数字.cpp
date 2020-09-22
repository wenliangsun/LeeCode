#include <bits/stdc++.h>

using namespace std;

/**
 * 题目440：字典序的第k小数字
 */

class Solution {
public:
    /**
     * 字典序，十叉树
     */
    int findKthNumber(int n, int k) {
        typedef long long LL;
        int cur = 1; // 当前值
        k--;
        while (k > 0) {
            LL a = cur, b = cur + 1;
            LL sum = 0; // 计算a,b区间有多少结点
            while (a <= n) {
                sum += min(n + 1ll, b) - a;
                a *= 10;
                b *= 10;
            }
            if (sum <= k) {
                k -= sum;
                cur++;
            } else {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};