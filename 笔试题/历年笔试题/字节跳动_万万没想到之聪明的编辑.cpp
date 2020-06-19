#include <bits/stdc++.h>

using namespace std;

/**
 * 头条题目：给定一个字符串按规则删除其中的字符，输出删除后的字符串
 * (1)aaa 删掉最后一个字符
 * (2)aabb 删掉最后一个字符
 *
 * 思路：模拟题
 */

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            s[k++] = s[i];
            if (k >= 3 && s[k - 3] == s[k - 2] && s[k - 2] == s[k - 1]) k--;
            if (k >= 4 && s[k - 4] == s[k - 3] && s[k - 2] == s[k - 1]) k--;
        }
        s.erase(s.begin() + k, s.end());
        cout << s << endl;
    }
    return 0;
}