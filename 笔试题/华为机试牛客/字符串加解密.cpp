#include <iostream>
#include <string>

using namespace std;

/**
 * 加密：
 * 当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,
 * 如字母a时则替换为B；字母Z时则替换为a；当内容是数字时则把该数字加1，
 * 如0替换1，1替换2，9替换0；其他字符不做变化
 * 
 * 解密：是加密的逆过程
 */

string jiami(string s1) {
    string res = "";
    for (auto c : s1) {
        if (c >= 'a' && c <= 'z') {
            char tmp = c + 1;
            if (tmp > 'z')
                tmp = tmp - 'z' + 'A' - 1;
            else
                tmp = tmp - 32;
            res += tmp;
        } else if (c >= 'A' && c <= 'Z') {
            char tmp = c + 1;
            if (tmp > 'Z')
                tmp = tmp - 'Z' + 'a' - 1;
            else
                tmp = tmp + 32;
            res += tmp;
        } else if (c >= '0' && c <= '9') {
            char tmp = c + 1;
            if (tmp > '9') tmp = tmp - '9' + '0' - 1;
            res += tmp;
        } else {
            res += c;
        }
    }
    return res;
}

string jiemi(string s) {
    string res = "";
    for (auto c : s) {
        if (c >= 'a' && c <= 'z') {
            char tmp = c - 1;
            if (tmp < 'a')
                tmp = 'Z';
            else
                tmp = tmp - 32;
            res += tmp;
        } else if (c >= 'A' && c <= 'Z') {
            char tmp = c - 1;
            if (tmp < 'A') {
                tmp = 'z';
            } else
                tmp = tmp + 32;
            res += tmp;
        } else if (c >= '0' && c <= '9') {
            char tmp = c - 1;
            if (tmp < '0') tmp = '9';
            res += tmp;
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    string s1;
    string s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        string res1 = jiami(s1);
        string res2 = jiemi(s2);
        cout << res1 << endl;
        cout << res2 << endl;
    }
    return 0;
}