#include <iostream>
#include <vector>

using namespace std;

/**
 * 有n个数，每个数有k个属性值，对于任意的两个数ai和aj，
 * 如果 ai1+aj1 = ai2+aj2 = ...=aik+ajk,则成ai和aj是一对完美数。
 * 求这n个数中总共有多少对完美数
 *
 * 输入 n，k
 * n行，每行k个属性
 *
 * 输出 总共有多少对完美数
 */

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<vector<int>> g;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                tmp.push_back(x);
            }
            g.push_back(tmp);
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = 0;
                int sum = g[i][0] + g[j][0];
                for (t = 1; t < k; t++) {
                    if (g[i][t] + g[j][t] != sum) break;
                }
                if (t == k) res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}