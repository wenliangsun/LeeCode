#include <bits/stdc++.h>

using namespace std;

/**
 * 牛客：程序员代码面试指南
 * 计算数组的小和
 * 
 * 思路：归并排序的思路，和逆序对非常像。
 */

typedef long long LL;

LL res = 0;

void mergesort(vector<int>& nums, int l, int r, vector<int>& tmp) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergesort(nums, l, mid, tmp);
    mergesort(nums, mid + 1, r, tmp);
    int idxl = l, idx = l, idxr = mid + 1;
    while (l <= mid && idxr <= r) {
        if (nums[l] <= nums[idxr]) {
            res += nums[l] * (r - idxr + 1);
            tmp[idx++] = nums[l++];
        } else tmp[idx++] = nums[idxr++];
    }
    while (l <= mid) tmp[idx++] = nums[l++];
    while (idxr <= r) tmp[idx++] = nums[idxr++];
    while (idxl <= r) nums[idxl] = tmp[idxl], idxl++;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<int> tmp(n);
    mergesort(nums, 0, nums.size() - 1, tmp);
    cout << res << endl;
    return 0;
}