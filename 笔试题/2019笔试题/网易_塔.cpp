#include <bits/stdc++.h>

using namespace std;

/**
 * 小易有一些立方体，每个立方体的边长为1，他用这些立方体搭了一些塔。
 * 现在小易定义：这些塔的不稳定值为它们之中最高的塔与最低的塔的高度差。
 * 小易想让这些塔尽量稳定，所以他进行了如下操作：每次从某座塔上取下一块立方体，并把它放到另一座塔上。
 * 现在小易想要知道，他进行了不超过k次操作之后，不稳定值最小是多少。
 *
 * 模拟题：遍历数组  找最大最小 然后更新数组即可
 */

const int N = 110;
typedef pair<int, int> PII;

int a[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = INT_MAX, cnt = 0;
    vector<PII> res;
    for (int i = 0; i < k; i++) {
        cnt++;
        // 扫描所有的塔  找最大值和最小值并记录他们的位置
        auto tmax = make_pair(INT_MIN, -1), tmin = make_pair(INT_MAX, -1);
        for (int i = 0; i < n; i++) {
            tmax = tmax.first < a[i] ? make_pair(a[i], i) : tmax;
            tmin = tmin.first > a[i] ? make_pair(a[i], i) : tmin;
        }
        s = min(s, tmax.first - tmin.first);  // 计算不稳定性
        res.push_back({tmax.second + 1, tmin.second + 1});  // 记录过程
        a[tmax.second]--, a[tmin.second]++;  // 更新塔的高度
        if (s == 0) break;
    }
    // 计算操作过后塔的不稳定性
    auto tmax = make_pair(INT_MIN, -1), tmin = make_pair(INT_MAX, -1);
    for (int i = 0; i < n; i++) {
        tmax = tmax.first < a[i] ? make_pair(a[i], i) : tmax;
        tmin = tmin.first > a[i] ? make_pair(a[i], i) : tmin;
    }
    s = min(s, tmax.first - tmin.first);
    cout << s << ' ' << cnt << endl;
    for (auto item : res) {
        cout << item.first << ' ' << item.second << endl;
    }
    return 0;
}