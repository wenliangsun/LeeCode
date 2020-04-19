#include <iostream>
#include <string>

using namespace std;

/**
 * 写出一个程序，接受一个字符串，
 * 然后输出该字符串反转后的字符串。（字符串长度不超过1000）
 */

int main() {
    string s;
    getline(cin, s);
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
}