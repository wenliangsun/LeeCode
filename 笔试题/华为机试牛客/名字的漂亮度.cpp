#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * 给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。
 * 每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。
 * 给出多个名字，计算每个名字最大可能的“漂亮度”。
 */

int main() {
    int n;
    while (cin >> n) {
        while (n--) {
            string s;
            cin >> s;
            int mp[26] = {0};
            for (auto c : s) {
                if (c >= 'a' && c <= 'z') mp[c - 'a']++;
                if (c >= 'A' && c <= 'Z') mp[c - 'A']++;
            }
            sort(mp, mp + 26), reverse(mp, mp + 26);
            int res = 0;
            for (int i = 0; i < 26; i++) {
                res += (26 - i) * mp[i];
            }
            cout << res << endl;
        }
    }
    return 0;
}