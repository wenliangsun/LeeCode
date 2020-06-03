#include <bits/stdc++.h>

using namespace std;

/**
 * 对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。
 *
 * 和网易互娱的字符串编码一样的题目
 */

int main() {
    string s;
    cin >> s;
    int i = 0, n = 1;
    while (i < s.size()) {
        if (s[i + 1] == s[i])
            n++;
        else {
            cout << n << s[i];
            n = 1;
        }
        i++;
    }
    return 0;
}