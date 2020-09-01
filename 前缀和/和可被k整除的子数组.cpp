#include <bits/stdc++.h>

using namespace std;

/**
 *  和可被k整除的子数组
 */

class Solution {
   public:
    /**
     * 前缀和
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + A[i - 1];
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((pre[j] - pre[i]) % K == 0) res++;
            }
        }
        return res;
    }

    /**
     * 前缀和 + 哈希 + 同余定理
     * 同余定理：如果整数a和整数满足a-b能够被m整除，即(a-b)%m==0,则a对m取余与b对m取余相等，即a%m==b%m。
     * 如果两个数的差能被K整除，就说明这两个数 mod K得到的结果相同，
     * 只要找有多少对 mod k 相同的数就可以组合一下得到结果。
     * 时间复杂度：O(n)
     * 空间复杂度：O(k)
     */
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> hash;
        hash[0] = 1; // 元素单独可以被k整除的情况
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre += A[i]; // 前缀和
            // 由于数组中有可能出现负数，我们需要将其加 K 从而使其 %K 之后的值为正数。
            pre = (pre % K + K) % K;
            hash[pre]++;
        }

        int res = 0;
        // 找有多少对 mod k 相同的数就可以组合一下得到结果。
        for (auto item : hash) {
            res += item.second * (item.second - 1) / 2;
        }
        return res;
    }
};