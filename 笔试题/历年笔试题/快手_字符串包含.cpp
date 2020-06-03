#include <bits/stdc++.h>

using namespace std;

/**
 * 我们定义字符串包含关系：字符串A=abc，字符串B=ab，字符串C=ac，则说A包含B，A和C没有包含关系。
 */

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1.find(s2) != s1.npos || s2.find(s1) != s2.npos)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}