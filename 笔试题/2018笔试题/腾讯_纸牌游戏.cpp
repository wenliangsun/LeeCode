#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
 * 牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出,
 * 直到纸牌被抽完。 他们的得分等于他们抽到的纸牌数字总和。
 * 现在假设牛牛和羊羊都采用最优策略,
 * 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。
 *
 * 模拟法！，排序
 */

int main() {
    int n;
    while (cin >> n) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end()), reverse(p.begin(), p.end());
        int niu = 0, yang = 0;
        for (int i = 0; i < p.size(); i++) {
            if ((i + 1) % 2)
                niu += p[i];
            else
                yang += p[i];
        }
        cout << niu - yang << endl;
    }
    return 0;
}
