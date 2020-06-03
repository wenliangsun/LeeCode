#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 题目：我们称一个矩阵为黑白矩阵，当且仅当对于该矩阵中每一个位置如(i, j)，
 * 其上下左右四个方向的数字相等，即(i-1, j)、(i+1, j)、(i, j-1)、(i, j+1)
 * 四个位置上的数字两两相等且均不等于(i, j)位置上的数字。（超出边界的格子忽略）
 * 现在给出一个 n*m
 * 的矩阵，我们想通过修改其中的某些数字，使得该矩阵变成黑白矩阵，
 * 请问最少需要修改多少个数字。
 */

typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> AS, BS;

    // 读取数组并统计奇数和偶数位的数字的次数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if ((i + j) % 2) {
                AS[x]++;
            } else {
                BS[x]++;
            }
        }
    }
    vector<PII> A, B;
    // 转换成vector 按照次数进行排序
    for (auto item : AS) {
        A.push_back({item.second, item.first});
    }
    for (auto item : BS) {
        B.push_back({item.second, item.first});
    }
    // 排序 递减
    sort(A.begin(), A.end()), reverse(A.begin(), A.end());
    sort(B.begin(), B.end()), reverse(B.begin(), B.end());
    int res = 0;  // 记录要保留的数的个数
    // 枚举奇数位和偶数位的前两个
    for (int i = 0; i < 2 && i < A.size(); i++) {
        for (int j = 0; j < 2 && j < B.size(); j++) {
            if (A[i].second == B[j].second) {
                // 如果数字相等，只能要一个
                res = max(res, max(A[i].first, B[j].first));
            } else {
                // 如果数字不相等，则两个都要
                res = max(res, A[i].first + B[j].first);
            }
        }
    }
    // 特殊情况
    if (A.empty()) res = B[0].first;
    if (B.empty()) res = A[0].first;

    cout << n * m - res << endl;
}
