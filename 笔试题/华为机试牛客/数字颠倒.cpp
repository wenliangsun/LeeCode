#include <iostream>
#include <string>

using namespace std;

/**
 * 输入一个整数，将这个整数以字符串的形式逆序输出
 * 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
 */

int main() {
    int n;
    cin >> n;
    string s = to_string(n);
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    cout << res << endl;
}