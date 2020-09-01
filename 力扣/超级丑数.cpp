#include <bits/stdc++.h>

using namespace std;

/**
 * 题目313：超级丑数
 */

class Solution {
public:
    /**
     * 和丑数的思路一样，只生成丑数，只不过因子不是固定的，可以用一个数组来存每个因子的指针
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> idxs(k); // k个指针
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            int minV = INT_MAX;
            for (int j = 0; j < k; j++) {
                minV = min(minV, res[idxs[j]] * primes[j]);
            }
            for (int j = 0; j < k; j++) {
                if (minV == res[idxs[j]] * primes[j]) idxs[j]++;
            }
            res[i] = minV;            
        }
        return res[n - 1];
    }
};