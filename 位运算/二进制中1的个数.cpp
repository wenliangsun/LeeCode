#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);  // 消除n的二进制中的最后一个1
        }
        cout << res << endl;
    }
    return 0;
}