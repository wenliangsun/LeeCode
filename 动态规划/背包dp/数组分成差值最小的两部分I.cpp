#include <bits/stdc++.h>

using namespace std;

/**
 * 将一个数组分成两部分，不要求两部分所包含的元素个数相等，要求使得这两个部分的和的差值最小。
 * 比如对于数组{1,0,1,7,2,4}，可以分成{1,0,1,2,4}和{7}，使得这两部分的差值最小。
 */

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int sum = 0;
    for (auto n : nums) sum += n;
    vector<int> dp(sum / 2 + 1);
    for (auto n : nums) {
        for (int j = sum / 2; j >= n; j--) {
            dp[j] = max(dp[j], dp[j - n] + n);
        }
    }
    cout << sum - dp[sum / 2] * 2 << endl;
    return 0;
}