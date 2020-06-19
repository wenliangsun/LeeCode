#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int res = -1, last = INT_MIN;
    for (auto n : nums) {
        int t = max(last, 0) + n;
        res = max(res, t);
        last = t;
    }
    cout << res << endl;
    return 0;
}