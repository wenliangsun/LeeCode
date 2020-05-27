#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

typedef long long LL;

int a[N], t[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    LL res = 0;
    // 先统计清醒时候的知识点分值
    for (int i = 0; i < n; i++)
        if (t[i]) res += a[i];
    // 将清醒时的分值置为0
    for (int i = 0; i < n; i++) a[i] = t[i] ? 0 : a[i];
    LL tt = 0, sum = 0;
    // 统计在k区间获得的最大值 也即叫醒后获得的知识点分值
    for (int i = 0, j = 0; j < n; j++) {
        if (j + 1 <= k)
            sum += a[j];
        else {
            tt = max(tt, sum);
            sum += a[j];
            sum -= a[i];
            i++;
        }
    }
    // 特判窗口和区间长度一样的情况
    if (n == k)
        for (int i = 0; i < n; i++) res += a[i];
    cout << res + tt << endl;
    return 0;
}