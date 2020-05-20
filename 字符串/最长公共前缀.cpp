#include <bits/stdc++.h>

using namespace std;

// 暴力扫描
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    string temp = strs[0];
    int index = 0;
    for (index; index < temp.size(); index++) {
        for (int i = 0; i < strs.size(); i++) {
            if (temp[index] != strs[i][index]) {
                return temp.substr(0, index);
            }
        }
    }
    return temp;
}

int main() {
    vector<string> strs;
    string s;
    while (cin >> s) {
        strs.push_back(s);
    }
    // 水平扫描法
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        // 如果当前字符串中不存在前缀prefix，则丢掉前缀的最后一个字符直到存在。
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) {
                puts(" ");
            }
        }
    }
    cout << prefix << endl;
    return 0;
}