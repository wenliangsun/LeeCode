#include <bits/stdc++.h>

using namespace std;

/**
 * 三数之和为k的所有组合
 */

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] == k - nums[i]) {
                if (l == i + 1 || nums[l] != nums[l - 1])
                    cout << nums[i] << ' ' << nums[l] << ' ' << nums[r] << endl;
                l++, r--;
            } else if (nums[l] + nums[r] > k - nums[i]) r--;
            else l++;
        }
    }
    return 0;
}