#include <bits/stdc++.h>

using namespace std;

/**
 * 题目974：和可被k整除的子数组 拼多多笔试
 */

class Solution {
   public:
    /**
     * 思路：前缀和 + 哈希 + 同余定理
     * 如果两个数的差能被K整除，就说明这两个数 mod K得到的结果相同，
     * 只要找有多少对 mod k 相同的数就可以组合一下得到结果。
     * 时间复杂度：O(N)
     * 空间复杂度：O(K)
     */
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> hash;
        hash[0] = 1;  // 元素单独可以被k整除
        for (int i = 0; i < A.size(); i++) {
            // 如果为负数时，需要转换为正数，这个转换原理，就是如果两个余数相加等于0，可以转换为相减等于0
            A[i] = (((i == 0 ? 0 : A[i - 1]) + A[i]) % K + K) % K;
            hash[A[i]]++;
        }
        int res = 0;
        for (auto item : hash) {
            res += item.second * (item.second - 1) / 2;
        }
        return res;
    }
};