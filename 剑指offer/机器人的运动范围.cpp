#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int res = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    vector<vector<bool>> st;
    int movingCount(int m, int n, int k) {
        st = vector<vector<bool>>(m, vector<bool>(n));
        dfs(m, n, 0, 0, k);
        return res;
    }

    /**
     * 深度优先搜索， 二维搜索的常用套路
     */
    void dfs(int m, int n, int x, int y, int k) {
        if (digit(x) + digit(y) > k || st[x][y]) return;
        res++;
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n) dfs(m, n, a, b, k);
        }
    }

    int digit(int n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};