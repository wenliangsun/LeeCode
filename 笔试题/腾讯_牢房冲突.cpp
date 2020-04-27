#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 有n个牢房，编号为1~n,每个牢房中都包含一个，每个人都可以在1~m中选择一个数字，
 * 如果有相邻牢房选择的数字相同，则会发生冲突。
 * 求发生冲突的情况有多少种？结果取mod100003.
 *
 * 输入m，n
 * 输出发生冲突的情况
 */

const int mod = 100003;
typedef long long LL;

int main() {
    LL m, n;
    while (cin >> m >> n) {
        // LL res = m * (n - 1) * pow(m, n - 2) - (n - 2)*m;
        // res %= mod;
        // cout << res << endl;
        unordered_set<LL> set;
    }
}