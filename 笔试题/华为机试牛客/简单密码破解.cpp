#include <iostream>
#include <string>

using namespace std;

/**
 * https://www.nowcoder.com/practice/7960b5038a2142a18e27e4c733855dac?tpId=37&tqId=21244&tPage=1&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking
 */

int main() {
    string s;
    while (getline(cin, s)) {
        string res = "";
        int mp[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
                      6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                res += to_string(mp[c - 'a']);
            } else if (c >= 'A' && c <= 'Z') {
                char tmp = c + 32 + 1;
                if (tmp > 'z') {
                    tmp = tmp - 'z' + 'a' - 1;
                }
                res += tmp;
            } else {
                res += c;
            }
        }
        cout << res << endl;
    }
    return 0;
}