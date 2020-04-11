#include <iostream>
#include <string>

using namespace std;

/**
 * 题目：最长的连续N串，最多允许有两个其它字符。
 *
 * 思路：双指针 滑动窗口
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int l = 0, r = 0;
        int times = 0;
        int res = 0;

        while (r < s.size()) {
            if (s[r] == 'N') {
                r++;
            } else if (s[r] != 'N' && times < 2) {
                times++;
                r++;
            } else {
                while (times >= 2 && l < r) {
                    if (s[l] != 'N') {
                        times--;
                    }
                    l++;
                }
            }
            res = max(res, r - l);
        }
        cout << res << endl;
    }
}