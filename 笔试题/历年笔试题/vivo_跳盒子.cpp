#include <bits/stdc++.h>

using namespace std;

/**
 * 和跳跃游戏一样
 */

int main() {
    vector<int> a;
    int n;
    while (cin >> n) a.push_back(n);
    int res = 0, e = 0, maxpos = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if (i > maxpos) {
            cout << -1 << endl;
            break;
        }
        maxpos = max(maxpos, a[i] + i);
        if (i == e) {
            e = maxpos;
            res++;
        }
    }
    cout << res << endl;
}