#include <bits/stdc++.h>

using namespace std;

/**
 * 和最长连续序列一样
 */

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) cin >> nums[i];
    unordered_set<int> hash;
    for (auto n : nums) hash.insert(n);
    int res = 0;
    for (auto n : nums) {
        if (!hash.count(n - 1)) {
            int cnt = 0;
            while (hash.count(n)) cnt++, n++;
            res = max(res, cnt);
        }
    }
    cout << res << endl;
    return 0;
}