#include <iostream>

using namespace std;

/**
 * 小Q在玩一款打怪兽的游戏，他在之前的关卡已经获得了足够多的金币，
 * 当前关有n个怪兽，每个怪兽有Ci的血量，打死它可以获得wi的金币，
 * 问小Q通过当前关卡最多可以多获得多少金币。
 *
 * 输入 n, m  // n表示怪兽的数量，m是一个金币可以购买的血量
 * n行，每行是一个怪兽的血量和打死它获得的金币
 */

const int N = 1010;

int c[N], w[N];

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> w[i];
        }
        int cost = 0;   // 记录买血花了多少钱
        int blood = 0;  // 记录自己拥有的血量
        int gain = 0;   // 记录打怪兽获得的金币
        // 遍历每一只怪兽，可以选择打或者不打
        for (int i = 0; i < n; i++) {
            // 先购买可以打死当前怪兽的血量
            int cnt = 0;
            while (blood < c[i]) {
                cnt++;
                blood += m;
            }
            //如果买血花的金币小于等于打死获得的金币，说明值得打
            if (cnt - w[i] <= 0) {
                cost += cnt;
                blood -= c[i];
                gain += w[i];
                // 否则选择不打
            } else {
                blood -= cnt * m;
            }
        }
        cout << gain - cost << endl;
    }
    return 0;
}