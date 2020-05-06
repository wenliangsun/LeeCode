#include <bits/stdc++.h>

using namespace std;

int main() {
    uint32_t n;
    while (cin >> n) {
        uint32_t res = 0, power = 31;
        while (n) {
            // 将最后一位移动到对应的位置与之前的结果相加
            res += (n & 1) << power;
            // 更新最后一位
            n = n >> 1;
            // 更新当前位移到的步数
            power--;
        }
        cout << res << endl;
    }
    return 0;
}