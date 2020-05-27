#include <iostream>
#include <string>

using namespace std;

/**
 * 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
 * 你能帮帮小Q吗？
 */

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n - cnt; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                char c = s[i];
                cnt++;
                for (int j = i; j < n - 1; j++) {
                    s[j] = s[j + 1];
                }
                s[n - 1] = c;
                i--;
            }
        }
        cout << s << endl;
    }
    return 0;
}