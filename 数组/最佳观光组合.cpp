#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1014：最佳观光组合
 */

class Solution {
   public:
    /**
     * 暴力
     * 时间复杂度：O(n^2)
     */
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = i + 1; j < A.size(); j++) {
                res = max(res, A[i] + A[j] + i - j);
            }
        }
        return res;
    }

    /**
     * 时间复杂度：O(n)
     * 将A[i] + A[j] + i - j拆分成两部分，A[i] + i 和 A[j] + j，这样在对于统计景点j时，
     * 由于A[j] - j 是固定的，我们只需要记录在区间[0,j-1]中A[i] + i的最大值mx，
     * 再加上A[j] - j即可
     */
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); j++) {
            res = max(res, mx + A[j] - j);
            mx = max(mx, A[j] + j);
        }
        return res;
    }
};