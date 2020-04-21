#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 编写一个程序，将输入字符串中的字符按如下规则排序。
 * 1.英文字母从 A 到 Z 排列，不区分大小写。
 * 2.同一个英文字母的大小写同时存在时，按照输入顺序排列
 * 3.非英文字母的其它字符保持原来的位置。
 */

int main() {
    string s;
    while (getline(cin, s)) {
        vector<char> res;
        // 字母顺序
        for (int i = 0; i < 26; i++) {
            // 从字符串中寻找字符，并排序存进res中
            for (int j = 0; j < s.size(); j++) {
                if (s[j] - 'a' == i || s[j] - 'A' == i) {
                    res.push_back(s[j]);
                }
            }
        }
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            // 如果是字符，从res中取
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                if (idx < res.size()) {
                    cout << res[idx];
                    idx++;
                }
                // 否则直接输出
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}