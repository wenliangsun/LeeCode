#include <bits/stdc++.h>

using namespace std;

int res = 0;

int mergesort(vector<int>& nums, int l, int r, vector<int>& t) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    mergesort(nums, l, mid, t);
    mergesort(nums, mid + 1, r, t);
    int idxl = mid, idxr = r, idx = r;
    while (idxl >= l && r >= mid + 1) {
        if (nums[idxl] > nums[r]) {
            res += r - mid;
            t[idx--] = nums[idxl--];
        } else {
            t[idx--] = nums[r--];
        }
    }
    while (idxl >= l) t[idx--] = nums[idxl--];
    while (r >= mid + 1) t[idx--] = nums[r--];
    while (idxr >= l) {
        nums[idxr] = t[idxr];
        idxr--;
    }
}

int helper(int size, vector<vector<int>>& swapidx) {
    vector<int> data;
    for (int i = 0; i < size; i++) data.push_back(i);
    for (auto idx : swapidx) {
        swap(data[idx[0]], data[idx[1]]);
    }
    vector<int> t(size);
    mergesort(data, 0, size - 1, t);
    return res % 2 ? 1 : 2;
}

int main() {
    vector<vector<int>> swapidx = {{2, 4}, {1, 4}, {0, 3}, {0, 3}};
    int ans = helper(5, swapidx);
    cout << ans << endl;
    return 0;
}