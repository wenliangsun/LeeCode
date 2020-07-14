#include <bits/stdc++.h>

using namespace std;

/**
 * 石子游戏II
 */

class Solution {
   public:
    // 花花酱视频：https://www.youtube.com/watch?v=e_FrC5xavwI
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n + 1));
        int s = score(piles, 0, 1, memo);
        int total = accumulate(piles.begin(), piles.end(), 0);
        return (total + s) / 2;
    }

    int score(vector<int>& piles, int s, int m, vector<vector<int>>& memo) {
        int n = piles.size();
        if (s >= n) return 0;
        m = min(m, n);
        if (memo[s][m]) return memo[s][m];
        if (s + 2 * m >= n)
            return accumulate(piles.begin() + s, piles.end(), 0);
        int res = INT_MIN, cur = 0;
        for (int x = 1; x <= 2 * m; x++) {
            cur += piles[s + x - 1];
            res = max(res, cur - score(piles, s + x, max(x, m), memo));
        }
        memo[s][m] = res;
        return res;
    }
};