#include <bits/stdc++.h>

using namespace std;

/**
 * 题目793：阶乘函数后k个零
 */

class Solution {
   public:
    typedef long long LL;
    /**
     * 二分查找
     * 时间复杂度：O((logk)^2)
     */
    int preimageSizeFZF(int K) {
        LL l = K, r = 10ll * K + 1;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            LL t = helper(mid);
            if (t == K) return 5;
            else if (t > K) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }

    LL helper(LL mid) {
        LL res = 0;
        while (mid) {
            res += mid / 5;
            mid /= 5;
        }
        return res;
    }
};