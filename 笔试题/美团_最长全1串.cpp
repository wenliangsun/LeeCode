#include <iostream>

using namespace std;

/**
 * 给你一个01字符串，定义答案=该串中最长的连续1的长度，现在你有至多K次机会，
 * 每次机会可以将串中的某个0改成1，现在问最大的可能答案.
 *
 * 思路：滑动窗口法，双指针，窗口中维护k个0
 */

const int N = 300010;

int n, k;
int a[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0, res = 0;
    while (r < n) {
        if (a[r] == 1)
            r++;
        else if (k > 0) {
            k--, r++;
        } else {
            res = max(res, r - l);
            while (l < r && a[l] == 1) {
                l++;
            }
            l++;
            r++;
        }
    }
    res = max(res, r - l);  // 考虑k没用完的情况
    cout << res << endl;
}