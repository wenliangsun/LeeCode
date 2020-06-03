#include <iostream>
#include <map>

using namespace std;

/**
 * 题目：如果特征< a, b >在持续帧里出现，那么它将构成特征运动。比如，特征< a, b
 * >在第2/3/4/7/8帧出现，
 * 那么该特征将形成两个特征运动2-3-4和7-8。现在，给定每一帧的特征，特征的数量可能不一样。
 * 小明期望能找到最长的特征运动。 https://www.acwing.com/problem/content/731/
 */

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    int res = 0;
    // 记录该特征上一次出现的帧数，以及连续出现的次数
    map<PII, int> last_time, count;
    for (int i = 1; i <= n; i++) {
        int m;
        for (int j = 0; j < m; j++) {
            PII t;
            cin >> t.first >> t.second;
            // 上一帧接着
            if (last_time[t] == i - 1) {
                count[t]++;
                last_time[t] = i;
                // 和上一帧没接
            } else if (last_time[t] < i - 1) {
                last_time[t] = i;
                count[t] = 1;
            }
            res = max(res, count[t]);
        }
    }
    cout << res << endl;
    return 0;
}
