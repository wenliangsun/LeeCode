#include <iostream>

using namespace std;

/**
 * 公园里有N个花园，初始时每个花园里都没有种花，
 * 园丁将花园从1到N编号并计划在编号为i的花园里恰好种A_i朵花，
 * 他每天会选择一个区间[L，R]（1≤L≤R≤N）并在编号为L到R的花园里各种一朵花，
 * 那么园丁至少要花多少天才能完成计划？
 */

const int N = 100010;
int n;
int a[N];

/**
 * 递归思路会报内存
 */
int countA(int a[], int l, int r) {
    int res = 0;
    if (l == r) {
        res = a[l];
        return res;
    }

    int index = -1, minN = 10010;
    for (int i = l; i <= r; i++) {
        if (a[i] < minN) {
            minN = a[i];
            index = i;
        }
    }
    res += a[index];
    for (int i = l; i <= r; i++) {
        a[i] -= minN;
    }
    res += countA(a, l, index - 1);
    res += countA(a, index + 1, r);
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    // 贪心的思想，实质是生成了一个递增的序列
    for (int i = 0; i < n - 1; i++) {
        res += max(0, a[i] - a[i + 1]);
    }
    res += a[n - 1];
    cout << res << endl;

    // cout << countA(a, 0, n - 1) << endl;
}