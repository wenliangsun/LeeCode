#include <iostream>
#include <map>
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
 *
 * 思路：记录属性的变化值，让变化值作为键
 */

typedef pair<int, int> PII;

int main() {
    int n, k;
    while (cin >> n >> k) {
        int g[n][k];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++) cin >> g[i][j];

        map<vector<int>, int> hash;
        for (int i = 0; i < n; i++) {
            vector<int> key;
            // 记录属性的差值
            for (int j = 0; j < k - 1; j++)
                key.push_back(g[i][j + 1] - g[i][j]);
            hash[key]++;
        }
        map<vector<int>, int>::iterator it;
        int res = 0;
        for (it = hash.begin(); it != hash.end(); it++) {
            auto item = *it;
            vector<int> tmp = item.first;
            int val = item.second;
            vector<int> inv;
            bool flag = false;  // 用来标记差值是否为0
            for (int i = 0; i < tmp.size(); i++) {
                inv.push_back(-tmp[i]);
                if (tmp[i] != 0) flag = true;
            }
            if (true)  // 不为0，则完美数对数为当前次数与与它差值相反的次数的乘积
                res += val * hash[inv];
            else  // 为0的情况
                res += val * (val - 1);
        }
        // 因为每一对都计算了两次，需要除以2
        cout << res / 2 << endl;

        // 暴力法

        // int res = 0;
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int t = 0;
        //         int sum = g[i][0] + g[j][0];
        //         for (t = 1; t < k; t++) {
        //             if (g[i][t] + g[j][t] != sum) break;
        //         }
        //         if (t == k) res++;
        //     }
        // }
        // cout << res << endl;
    }
    return 0;
}