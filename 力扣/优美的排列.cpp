#include <bits/stdc++.h>

using namespace std;

/**
 * 题目526：优美的排列
 */

class Solution {
   public:
    int res = 0;
    vector<bool> st;
    /**
     * 回溯 + 剪枝
     */
    int countArrangement(int N) {
        st = vector<bool>(N + 1);
        dfs(N, 1);
        return res;
    }

    void dfs(int n, int idx) {
        if (idx > n) {
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (i % idx && idx % i) continue;
            if (!st[i]) {
                st[i] = true;
                dfs(n, idx + 1);
                st[i] = false;
            }
        }
    }
};