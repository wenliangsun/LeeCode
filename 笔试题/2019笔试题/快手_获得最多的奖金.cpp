#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
typedef long long LL;

LL d[N], preSum[N], posSum[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    // 计算前缀和
    for (int i = 1; i <= n; i++) preSum[i] = preSum[i - 1] + d[i - 1];
    // 计算后缀和
    for (int i = n; i > 0; i--) posSum[i] = posSum[i + 1] + d[i - 1];

    int l = 1, r = n;
    LL res = 0;
    // 双指针
    while (r - l > 1) {
        // 如果左侧小，左指针右移
        if (preSum[l] < posSum[r]) l++;
        // 如果右侧小，右指针左移
        else if (preSum[l] > posSum[r])
            r--;
        // 否则，更新答案
        else {
            res = max(res, preSum[l]);
            l++, r--;
        }
    }
    // 这儿需要特判 中间的一组为空且左右两侧的红包总和相等的情况
    if (l != r && preSum[l] == posSum[r]) res = max(res, preSum[l]);
    cout << res << endl;
    return 0;
}