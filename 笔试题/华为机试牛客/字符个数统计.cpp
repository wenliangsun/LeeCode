#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * 编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，
 * 换行表示结束符，不算在字符里。不在范围内的不作统计。
 */

int main() {
    string s;
    getline(cin, s);
    unordered_set<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > 0 && s[i] <= 127) {
            st.insert(s[i]);
        }
    }
    cout << st.size() << endl;
}