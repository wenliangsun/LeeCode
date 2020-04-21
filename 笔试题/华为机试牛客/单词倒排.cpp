#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * 对字符串中的所有单词进行倒排。
 * 
 * I am a student
 * 
 * student a am I
 */

int main() {
    string s;
    while (getline(cin, s)) {
        s += ' ';
        stack<string> stk;
        string tmp = "";
        for (auto c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                tmp += c;
            } else {
                if (!tmp.empty()) stk.push(tmp);
                tmp.clear();
            }
        }
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            res += ' ';
            stk.pop();
        }
        cout << res.substr(0, res.size() - 1) << endl;
    }
    return 0;
}