#include <climits>
#include <iostream>
#include <set>

using namespace std;

/**
 * 题目：给定一个长度为 n 的序列 A，A 中的数各不相同。对于 A 中的每一个数
 * Ai，求：min1≤j<i|Ai−Aj| 以及令上式取到最小值的 j（记为
 * Pi）。若最小值点不唯一，则选择使 Aj 较小的那个。
 *
 * 思路：set的使用  upper_bound  和 lower_bound
 */

int main() {
    int n;
    set<pair<int, int>> S;
    S.insert({INT_MIN, 0});  // 哨兵，方便处理边界
    S.insert({INT_MAX, 0});
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (i > 1) {
            auto it = S.upper_bound({v, 0});
            auto jt = it;
            jt--;
            int rv = it->first - v;
            int lv = v - jt->first;
            if (lv <= rv) {
                cout << lv << ' ' << jt->second << endl;
            } else {
                cout << rv << ' ' << it->second << endl;
            }
        }
        S.insert({v, i});
    }
}