#include <ctype.h>

#include <iostream>
#include <string>

using namespace std;

/**
 * https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3?tpId=37&tqId=21259&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 */

int main() {
    string m;
    while (getline(cin, m)) {
        int a[26] = {0};
        string s = "";
        for (auto c : m) {
            if ((c >= 'a' && c <= 'z') && a[c - 'a'] == 0) {
                s += c;
                a[c - 'a']++;
            } else if ((c >= 'A' && c <= 'Z') && a[c - 'A'] == 0) {
                s += c + 32;
                a[c - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (a[i] == 0) {
                s += 'a' + i;
            }
        }
        string b;
        getline(cin, b);
        string res = "";
        for (auto c : b) {
            if (c >= 'a' && c <= 'z')
                res += s[c - 'a'];
            else if (c >= 'A' && c <= 'Z')
                res += s[c - 'A'] - 32;
            else
                res += c;
        }
        cout << res << endl;
    }
    return 0;
}