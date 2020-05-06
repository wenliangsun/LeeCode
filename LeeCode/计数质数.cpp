#include <bits/stdc++.h>

using namespace std;

/**
 * 题目204：计数质数
 */

class Solution {
   public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }
};