#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * 将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am
 * I” 所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
 */

int main() {
    string s;
    getline(cin, s);
    int l = 0, r = 0;
    // 注意这儿的边界
    while (l < s.size()) {
        if (s[l] == ' ') {
            l++, r++;
        } else if (r == s.size() || s[r] == ' ') {
            cout << l << ' ' << r << endl;
            reverse(s.begin() + l, s.begin() + r);
            l = ++r;
        } else {
            r++;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}