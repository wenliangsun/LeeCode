#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n
 * 中没有出现在序列中的那个数
 */

int main() {
    int n;
    while (cin >> n) {
        int nums[n];
        for (int i = 0; i < n; i++) cin >> nums[i];
        int res = n;
        for (int i = 0; i < n; i++) {
            res ^= nums[i] ^ i;
        }
        cout << res << endl;
    }
    return 0;
}