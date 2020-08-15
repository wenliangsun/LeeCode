#include <bits/stdc++.h>

using namespace std;

int longest(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    return res;
}

int longest2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (dp[mid] >= nums[i]) r = mid;
            else l = mid + 1;
        }
        if (l == len) len++;
        dp[l] = nums[i];
    }
    return len;
}


int main() {
    vector<int> nums = {12,34,45,5,67,77,8,9,0};
    int res = longest2(nums);
    cout << res << endl;
    return 0;
}