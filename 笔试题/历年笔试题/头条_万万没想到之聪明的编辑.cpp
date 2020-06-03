#include <iostream>

using namespace std;

/**
 * 头条题目：给定一个字符串按规则删除其中的字符，输出删除后的字符串
 * (1)aaa 删掉最后一个字符
 * (2)aabb 删掉最后一个字符
 *
 * 思路：模拟题
 */

const int N = 1000010;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int k = 0;
        for (int i = 0; s[i]; i++) {
            s[k++] = s[i];
            if (k >= 3 && s[k - 3] == s[k - 2] && s[k - 2] == s[k - 1]) {
                k--;
            }
            if (k >= 4 && s[k - 4] == s[k - 3] && s[k - 2] == s[k - 1]) {
                k--;
            }
        }
        s[k] = '\0';
        cout << s << endl;
    }
    return 0;
}