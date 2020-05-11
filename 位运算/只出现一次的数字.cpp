#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 */

int main() {
    int n;
    while (cin >> n) {
        int nums[n];
        for (int i = 0; i < n; i++) cin >> nums[i];
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        cout << res << endl;
    }
    return 0;
}