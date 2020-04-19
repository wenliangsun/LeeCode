#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 给定n个字符串，请对n个字符串按照字典序排列。
 */

int main() {
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    sort(strs.begin(), strs.end());
    for (auto s : strs) {
        cout << s << endl;
    }
}