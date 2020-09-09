#include <bits/stdc++.h>

using namespace std;

/**
 * 输入两个字符串，找到第二个字符串在第一个字符串中的位置，并将其变为*。
 * 123456123 123
 * ***456***
 */

string helper(string s1, string s2) {
    string t(s2.size(), '*');
    int pos = s1.find(s2);
    while (pos != s1.npos) {
        s1.replace(pos, s2.size(), t);
        pos = s1.find(s2, pos + 1);
    }
    return s1;
}

int main() {
    string s1 = "123456123";
    string s2 = "123";
    string res = helper(s1,s2);
    cout << res << endl;
}