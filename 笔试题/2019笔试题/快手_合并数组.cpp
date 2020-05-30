#include <bits/stdc++.h>

using namespace std;

/**
 * 请实现一个函数，功能为合并两个升序数组为一个升序数组
 */

vector<int> split(string s) {
    vector<int> res;
    if (s.empty()) return res;
    s += ",";
    int pos = s.find(',');
    while (pos != s.npos) {
        res.push_back(stoi(s.substr(0, pos)));
        s = s.substr(pos + 1);
        pos = s.find(',');
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> num1 = split(s1);
    vector<int> num2 = split(s2);
    vector<int> res;
    int i = 0, j = 0;
    while (i < num1.size() && j < num2.size()) {
        if (num1[i] < num2[j])
            res.push_back(num1[i++]);
        else
            res.push_back(num2[j++]);
    }
    while (i < num1.size()) res.push_back(num1[i++]);
    while (j < num2.size()) res.push_back(num2[j++]);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << ',';
        }
    }
    return 0;
}