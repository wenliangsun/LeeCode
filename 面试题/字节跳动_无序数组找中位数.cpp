#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& nums, int l, int r) {
    int flag = l;
    int idx = l + 1;
    for (int i = idx; i <= r; i++) {
        if (nums[i] < nums[flag]) {
            swap(nums[i], nums[idx]);
            idx++;
        }
    }
    swap(nums[idx - 1], nums[flag]);
    return idx - 1;
}
// 快排的思想 平均时间复杂度：O(n)
int median(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    int mid = l + r >> 1;
    int idx = -1;
    while (idx != mid) {
        idx = partition(nums, l, r);
        if (idx < mid)
            l = idx + 1;
        else if (idx > mid)
            r = idx - 1;
        else
            break;
    }
    return nums[idx];
}

// 使用堆
double median2(vector<int>& nums) {
    priority_queue<int, vector<int>, less<int>> q;
    int n = nums.size();
    for (int i = 0; i <= n / 2; i++) {
        q.push(nums[i]);
    }
    for (int i = n / 2; i <= n; i++) {
        if (nums[i] <= q.top()) {
            q.pop();
            q.push(nums[i]);
        }
    }
    if (n % 2) return q.top();
    double t = q.top();
    q.pop();
    return (t + q.top()) / 2;
}

int main() {
    vector<int> nums = {1,       3,       43, 235,   453, 5234,
                        5235213, 4234545, 3,  41234, 333, 444};
    double res = median2(nums);
    cout << res << endl;
}