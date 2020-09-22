#include <bits/stdc++.h>

using namespace std;

/**
 * 给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序二元组
 */

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int l = 0, r = n - 1;
    while (l < r) {
        if (nums[l] + nums[r] == k) {
            if (l == 0 || nums[l] != nums[l - 1]) // 这儿需要去重
                cout << nums[l] << ' ' << nums[r] << endl;
            l++, r--;
        } else if (nums[l] + nums[r] > k)
            r--;
        else
            l++;
    }
    return 0;
}