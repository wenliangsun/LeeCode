#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 输入n个字符串（1<=n<=3*102，字符串总长度不超过103，只包含小写字母)后面多次查询，每次查询输入两个数字x，y，
 * 输出第x个字符串和第y个字符串的最长公共前缀长度。（查询次数不超过102）
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
    int a, b;
    while (cin >> a >> b) {
        string s1 = strs[a - 1], s2 = strs[b - 1];
        int len = s1.size() < s2.size() ? s1.size() : s2.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (s1[i] == s2[i]) {
                res++;
            } else {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}