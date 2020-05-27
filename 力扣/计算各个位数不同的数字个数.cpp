#include <bits/stdc++.h>

using namespace std;

/**
 * 题目357：计算各个位数不同的数字个数
 */

class Solution {
   public:
    int res = 0;
    vector<bool> st;
    /**
     * 思路：回溯法
     */
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        st = vector<bool>(10);
        dfs(n, 0);
        return res;
    }

    void dfs(int n, int idx) {
        res++;
        if (idx == n) return;
        for (int i = 0; i < 10; i++) {
            if (i == 0 && idx < 1) continue;
            if (!st[i]) {
                st[i] = true;
                dfs(n, idx + 1);
                st[i] = false;
            }
        }
    }

    /**
     * 找规律
     */
    int countNumbersWithUniqueDigits(int n) {
        if (!n) return 1;
        int a = 10, b = 9 * 9;
        for (int i = 2; i <= n; i++) {
            a += b;
            b *= 10 - i;
        }
        return a;
    }
};