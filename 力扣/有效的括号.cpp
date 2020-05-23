#include <map>
#include <stack>
#include <string>

using namespace std;

/**
 * 题目20：有效的括号
 */
class LeeCode20 {
   public:
    /**
     * 思路：利用栈数据结构
     */
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        // map 用来存储括号对
        map<char, char> m = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty()) {  //如果stk是空的话则入栈
                stk.push(s[i]);
                // 判断栈顶元素和当前字符是否匹配
            } else if (m[stk.top()] == s[i]) {  // 若匹配，则出栈
                stk.pop();
            } else {
                stk.push(s[i]);  // 不匹配，则入栈
            }
        }
        return stk.empty();
    }
};