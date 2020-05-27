#include <bits/stdc++.h>

using namespace std;

/**
 * 牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。
 * 从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
 */

const int N = 110;

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    vector<PII> clks;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        clks.push_back({a, b});
    }
    int time;
    cin >> time;
    int a, b;
    cin >> a >> b;
    // 对闹钟排序
    sort(clks.begin(), clks.end());
    int i;
    // 从小到大遍历每个闹钟
    for (i = 0; i < clks.size(); i++) {
        auto ck = clks[i];
        int h = ck.first, m = ck.second;
        if (b < m) {
            b += 60, a--;
        }
        int tmp = (a - h) * 60 + b - m;
        // 如果当前闹钟不能满足要求，跳出循环，前一个闹钟就是答案
        if (tmp < time) break;
    }
    cout << clks[i - 1].first << ' ' << clks[i - 1].second << endl;
    return 0;
}