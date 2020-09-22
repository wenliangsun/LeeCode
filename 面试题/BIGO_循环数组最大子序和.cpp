#include <bits/stdc++.h>

using namespace std;

/**
 * 分两种情况，第一种情况就直接计算整个数组的最大子序和，
 * 另一种情况计算数组的最小子数组和以及数组的总和，然后用总和减去最小子数组和，相当于从最小子数组处断开。
 * 这两种情况中取最大值。
 */
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int mx = INT_MIN, pre = 0;
    for (int i = 0; i < n; i++) {
        int t = max(pre, 0) + nums[i];
        mx = max(mx, t);
        pre = t;
    }

    int mn = 0, sum = 0;
    pre = 0;
    for (int i = 0; i < n; i++) {
        int t = min(pre, 0) + nums[i];
        mn = min(mn, t);
        pre = t;
        sum += nums[i];
    }
    int res = max(mx, sum - mn);
    return res;
}

// 力扣918题：环形子数组最大和 前缀和 + 单调队列

int maxSubarraySumCircular(vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) A.push_back(A[i]);
    vector<int> sum(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + A[i - 1];
    int res = INT_MIN;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= 2 * n; i++) {
        if (q.size() && i - n > q.front()) q.pop_front();
        if (q.size()) res = max(res, sum[i] - sum[q.front()]);
        while (q.size() && sum[q.back()] >= sum[i]) q.pop_back();
        q.push_back(i);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int res = maxSubarraySumCircular(nums);
    cout << res << endl;
    return 0;
}