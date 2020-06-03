#include <bits/stdc++.h>

using namespace std;

/**
 * 一个非空整数数组，选择其中的两个位置，使得两个位置之间的数和最大。
 * 如果最大的和为正数，则输出这个数；如果最大的和为负数或0，则输出0
 */

vector<int> split(string& s) {
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
    string s;
    cin >> s;
    vector<int> nums = split(s);
    int last = 0, res = INT_MIN;
    for (auto n : nums) {
        int t = max(last, 0) + n;
        res = max(res, t);
        t = res;
    }
    cout << (res < 0 ? 0 : res) << endl;
    return 0;
}