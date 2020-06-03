#include <iostream>
#include <string>

using namespace std;

/**
 * 二分法！！！
 */

int main() {
    int n;
    while (cin >> n) {
        int l = -90, r = 90;
        string res;
        int cnt = 6;
        while (l < r && cnt--) {
            int mid = (l + r) / 2;
            if (mid <= n) {
                l = mid;
                res += '1';
            } else if (mid > n) {
                r = mid;
                res += '0';
            }
        }
        cout << res << endl;
    }
    return 0;
}