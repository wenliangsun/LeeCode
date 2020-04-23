#include <stack>
#include <string>

using namespace std;

/**
 * 题目71：简化路径
 */
class LeeCode71 {
   public:
    /**
     * 思路：将路径利用'/'分割开。然后借助辅助栈来将简化后的路径存入栈
     * 然后将简化路径出栈并返回
     */
    string simplifyPath(string path) {
        if (path.empty()) {
            return path;
        }
        path += "/";  // 加个'/'是为了统一
        stack<string> stk;
        // 记录'/'分割的字符串
        string curDir = "";
        for (char c : path) {
            // 如果是'/'，就判断当前路径字符串是否需要入栈，或出栈上一个字符串
            if (c == '/') {
                // 如果是".."则出栈上一个字符串
                if (curDir == ".." && !stk.empty()) {
                    stk.pop();
                    // 否则考虑有效的字符串入栈
                } else if (curDir != ".." && curDir != "." && !curDir.empty()) {
                    stk.push(curDir);
                }
                curDir.clear();
            } else {
                curDir += c;
            }
        }
        string res = "";
        // 拼接简化路径字符串
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        // 如果是空的话，返回根目录，即'/'
        if (res.empty()) {
            res += "/";
        }
        return res;
    }
};