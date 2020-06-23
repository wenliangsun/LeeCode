#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int cnt = 0, res = INT_MAX;

int find(int x) { // 查找，不能使用路径压缩，因为要统计路径上有多少人，只查找的话可以进行路径压缩
    cnt++; // 统计最小环的长度
    if (x == p[x]) return x;
    return find(p[x]);
}

int main() {
    int n;
    cin >> n;
    p = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) p[i] = i; // 初始化
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt = 0; // 初始化
        if (find(x) == i) // 如果再一次遍历到了自己
            res = min(res, cnt); // 更新答案
        else
            p[i] = x; // 设置自己传递对象
    }
    cout << res << endl;
    return 0;
}