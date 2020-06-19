#include <bits/stdc++.h>

using namespace std;

/**
 * 小明是一名算法工程师，同时也是一名铲屎官。某天，他突发奇想，想从猫咪的视频里挖掘一些猫咪的运动信息。
 * 为了提取运动信息，他需要从视频的每一帧提取“猫咪特征”。一个猫咪特征是一个两维的vector<x, y>。
 * 如果x_1=x_2 and y_1=y_2，那么这俩是同一个特征。因此，如果喵咪特征连续一致，可以认为喵咪在运动。
 * 也就是说，如果特征<a, b>在持续帧里出现，那么它将构成特征运动。比如，特征<a, b>在第2/3/4/7/8帧出现，
 * 那么该特征将形成两个特征运动2-3-4 和7-8。现在，给定每一帧的特征，特征的数量可能不一样。
 * 小明期望能找到最长的特征运动
 * 
 * 思路：记录当前帧上当前特征上一次出现的位置，以及到上一次出现的位置的连续特征数量
 */

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int res = 0;
        // 记录该特征上一次出现的帧数，以及连续出现的次数
        map<PII, int> last_time, cnt;
        for (int i = 1; i <= m; i++) { // 索引从1开始
            int a;
            cin >> a;
            for (int j = 0; j < a; j++) {
                PII t;
                cin >> t.first >> t.second;
                // 当前帧与上一帧接着
                if (last_time[t] == i - 1) {
                    last_time[t] = i; // 上一次出现的位置更新为当前值
                    cnt[t]++; // 连续特征+1
                // 和上一帧没接上，判断是为了排除一行里面有相同的特征的情况
                } else if (last_time[t] < i - 1) {
                    last_time[t] = i; // 将上一次出现的位置更新为当前值
                    cnt[t] = 1; // 连续特征记为1
                }
                res = max(res, cnt[t]);
            }
        }
        cout << res << endl;
    }
    return 0;
}