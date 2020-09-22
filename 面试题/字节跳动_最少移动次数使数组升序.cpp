#include <bits/stdc++.h>

using namespace std;

/**
 * 最少的move次数，使得数组变成升序，问次数是多少？
 * 7 1 2 3 4 5 6 -> 1 2 3 4 5 6 7
 */

// 用总长度减去最长上升子序列的长度。
int minMove(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (dp[mid] >= nums[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (l == len) len++;
        dp[l] = nums[i];
    }
    return n - len;
}

int main() {
    vector<int> nums = {1, 2, 4, 5, 7, 3, 4, 5};
    int res = minMove(nums);
    cout << res << endl;
}