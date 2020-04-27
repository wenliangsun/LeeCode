#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
 * 每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量(放在同一侧)，
 * 问能称出多少种不同的重量。
 * 注:称重重量包括0
 */

int main() {
    int n;
    while (cin >> n) {
        vector<int> m(n), num(n);
        for (int i = 0; i < n; i++) cin >> m[i];
        for (int i = 0; i < n; i++) cin >> num[i];
        vector<int> w;                       // 存已经称出的重量
        for (int i = 0; i <= num[0]; i++) {  // 第一个砝码
            w.push_back(i * m[0]);
        }
        for (int i = 1; i < n; i++) {  // 遍历之后的砝码
            int len = w.size();
            for (int j = 1; j <= num[i]; j++) {  // 砝码的数量
                // 在之前的砝码的基础上增加当前砝码
                for (int k = 0; k < len; k++) {
                    int t = w[k] + m[i] * j;
                    // 去重复
                    if (find(w.begin(), w.end(), t) == w.end()) w.push_back(t);
                }
            }
        }
        cout << w.size() << endl;
    }
    return 0;
}