#include <iostream>
#include <string>

using namespace std;

/**
 * 实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。
 * 输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序。
 * 注意每个输入文件有多组输入，即多个字符串用回车隔开
 */

int main() {
    string s;
    while (getline(cin, s)) {
        int a[26] = {0};
        for (auto c : s) {
            a[c - 'a']++;
        }
        int minCnt = a[s[0] - 'a'];
        for (auto c : s) {
            if (a[c - 'a'] < minCnt) {
                minCnt = a[c - 'a'];
            }
        }
        for (auto c : s) {
            if (a[c - 'a'] > minCnt) cout << c;
        }
        cout << endl;
    }
    return 0;
}