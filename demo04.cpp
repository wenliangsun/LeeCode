#include <bits/stdc++.h>

using namespace std;

int LCS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (dp[mid] > nums[i]) 
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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i< n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    int res = LCS(nums);
    cout << res << endl;
}