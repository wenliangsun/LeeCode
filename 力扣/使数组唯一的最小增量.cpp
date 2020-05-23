#include <bits/stdc++.h>

using namespace std;

/**
 * 题目945：使数组唯一的最小增量 拼多多笔试
 */

class Solution {
   public:
    /**
     * 思路：排序， 贪心添加
     * 时间复杂度：O(nlogn)
     */
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] <= A[i - 1]) {
                res += (A[i - 1] - A[i] + 1);
                A[i] = A[i - 1] + 1;
            }
        }
        return res;
    }
};