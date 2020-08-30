#include <bits/stdc++.h>

using namespace std;

/**
 * 在2d的游戏中，所有怪兽都在x轴上，每个怪兽有两个属性x和hp，分别代表怪兽的位置和
 * 生命值，玩家控制的角色有一个AOE技能，玩家每次释放技能可以选择一个位置，
 * 技能会对[x-y,x+y]范围内的所有怪兽造成1点伤害，问玩家需要使用多少次技能才能杀死所有怪物。
 */

typedef long long LL;
typedef pair<LL, LL> PII;

int main() {
    int n, y;
    cin >> n >> y;
    vector<PII> a;
    for (int i = 0; i < n; i++) {
        LL x, hp;
        cin >> x >> hp;
        a.push_back({x, hp});
    }
    sort(a.begin(), a.end());
    LL res = 0;
    a.push_back({a.back().first + 1, 0});
    for (int i = 0; i < n; i++) {
        if (a[i].second == 0) continue;
        int j = i + 1;
        while (j < n &&  (a[j].first - a[i].first < 2 * y)) {
            a[j].second = a[j].second < a[i].second ? 0 : a[j].second-a[i].second;
            j++;
        }
        res += a[i].second;
    }
    cout << res << endl;

    return 0;
}