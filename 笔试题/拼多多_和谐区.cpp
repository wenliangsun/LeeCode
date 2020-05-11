#include <bits/stdc++.h>

using namespace std;

/**
 * 某个小区有1-n棵树，每棵树有个和谐值$A_i$，如果一段连续的树，
 * 他们和谐值之和可以被$m$整除，那么这个区间整体就是和谐的。
 * 求有多少个这样的区间?
 */

const int N = 100010;

int n, m;
int va[N];

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            cin >> va[i];
        }
        unordered_map<int, int> hash;
        hash[0] = 1;  // 考虑单个元素就可以整除m的情况
        for (int i = 0; i < n; i++) {
            // 前缀和对m取余
            va[i] = ((i == 0 ? 0 : va[i - 1]) + va[i]) % m;
            hash[va[i]]++;
        }
        int res = 0;
        for (auto item : hash) {
            // 对m取余相同的情况进行组合
            res += (item.second * (item.second - 1)) / 2;
        }
        cout << res << endl;
    }
    return 0;
}