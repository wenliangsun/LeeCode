#include <bits/stdc++.h>

using namespace std;

/**
 * 环形子数组的最大和
 *
 * 单调队列
 */

class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        // 将环形链表展成两倍的数组
        for (int i = 0; i < n; i++) A.push_back(A[i]);
        vector<int> sum(n * 2 + 1);
        // 求前缀和
        for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + A[i - 1];
        int res = INT_MIN;
        deque<int> q;
        q.push_back(0);  //  前缀和为0的情况
        for (int i = 1; i <= 2 * n; i++) {
            // i -n > q.front()) 如何理解？？
            if (q.size() && i - n > q.front()) q.pop_front();
            // 更新答案
            if (q.size()) res = max(res, sum[i] - sum[q.front()]);
            // 维护一个单调递减队列
            while (q.size() && sum[q.back()] >= sum[i]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};