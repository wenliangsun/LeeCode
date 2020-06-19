#include <bits/stdc++.h>

using namespace std;

/**
 * 春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，
 * 他是这样定义的：“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。 
 * 现在要求输出所有在m和n范围内的水仙花数。
 * 
 * 暴力穷举
 */

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<int> res;
        for (int i = m; i <= n; i++) {
            string s = to_string(i);
            int sum =
                pow(s[0] - '0', 3) + pow(s[1] - '0', 3) + pow(s[2] - '0', 3);
            string t = to_string(sum);
            if (s == t) res.push_back(i);
        }
        if (res.size()) {
            for (auto n : res) cout << n << ' ';
        } else
            cout << "no";
        cout << endl;
    }
}