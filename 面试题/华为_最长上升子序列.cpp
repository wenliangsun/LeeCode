#include <bits/stdc++.h>

using namespace std;

/**
 * 时间复杂度：O(nlogn)
 */
int LCS(vector<int>& nums) {
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
    return len;
}

int main() {
    vector<int> nums = {2, 1, 4, 3, 5, 6};
    int res = LCS(nums);
    cout << res << endl;
    return 0;
}