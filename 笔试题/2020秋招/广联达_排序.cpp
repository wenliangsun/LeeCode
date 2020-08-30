#include <bits/stdc++.h>

using namespace std;

/**
 * 有一种排序定义如下，该排序算法每次只能把一个元素提到序列的开头，
 * 现给你个乱序的1-n的排列，请计算最少需要多少次操作才可以使得原序列从小到大有序。
 */

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int mx = 0, t = n;
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] == t)
            t--;
        else
            mx = max(mx, nums[i]);
        if (mx + 1 == t) break;
    }
    cout << mx <<endl;
    return 0;
}