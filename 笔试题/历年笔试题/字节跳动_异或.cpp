#include <bits/stdc++.h>

using namespace std;

/**
 * 给定整数m以及n各数字A1,A2,..An，将数列A中所有元素两两异或，共能得到n(n-1)/2个结果，请求出这些结果中大于m的有多少个。
 */

const int N = 100010;

int n, m;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 0;
    // 暴力，过了80%的测试用例
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res += (a[i] ^ a[j]) > m;
        }
    }
    cout << res << endl;
    return 0;
}