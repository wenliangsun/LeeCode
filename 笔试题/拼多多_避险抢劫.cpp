#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 拼多多题目：小镇沿街分布（可以理解为都在数轴上），有n家银行（位置以数轴的坐标表示，
 * 金额表示可以被抢走的金额）。两个绑匪试图分别抢劫一个银行，为了让警方多奔波他们商定选择的两个银行距离不小于d。
 * 请问，符合约定的情况下他们能抢到的总金额最大是多少。
 * 
 * 时间好像会超！！！
 */

typedef pair<int, int> PII;

const int N = 200010;

int main() {
    int n, d;
    cin >> n >> d;
    PII banks[N];
    for (int i = 1; i <= n; i++) {
        cin >> banks[i].first >> banks[i].second;
    }
    // 按照坐标排序
    sort(banks + 1, banks + 1 + n);
    int res = 0;
    // 双指针法
    for (int i = 1; i <= n; i++) {
        int j = 0;
        int maxLeft = 0;
        // 向左寻找满足距离条件的金额最大的银行
        while (j + 1 < i && banks[i].first - banks[j + 1].first >= d) {
            j++;
            maxLeft = max(maxLeft, banks[j].second);
        }
        res = max(res, maxLeft + banks[i].second);
    }
    cout << res << endl;

    return 0;
}
