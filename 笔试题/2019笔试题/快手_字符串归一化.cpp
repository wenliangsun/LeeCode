#include <bits/stdc++.h>

using namespace std;

/**
 * 通过键盘输入一串小写字母(a~z)组成的字符串。
 * 请编写一个字符串归一化程序，统计字符串中相同字符出现的次数，并按字典序输出字符及其出现次数。
 *
 * 简单题
 */

int main() {
    string s;
    cin >> s;
    map<char, int> hash;
    for (auto c : s) hash[c]++;
    for (auto item : hash) cout << item.first << item.second;
    return 0;
}