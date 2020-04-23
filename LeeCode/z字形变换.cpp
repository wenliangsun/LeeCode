#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目6：Z字形变换
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 *
 */
class LeeCode06 {
   public:
    /**
     * 思路：遍历字符串，把每个字符赋给对应的行中，最后将各个行中的字符串拼接起来
     */
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string str;
        // 用一个容器来存每行的字符串，容器的大小为 numRows 和
        // s.size()中的较小者
        vector<string> res(min(numRows, int(s.size())));
        bool topDown = false;  // 设置遍历方向的标志位
        int curRow = 0;        // 当前行的索引
        for (int i = 0; i < s.size(); i++) {
            res[curRow] += s[i];
            if (curRow == 0 || curRow == numRows - 1) {  // 判断是否转换方向
                topDown = !topDown;
            }
            if (topDown) {
                curRow++;
            } else {
                curRow--;
            }
        }
        for (int i = 0; i < res.size(); i++) { // 拼接每行的字符串
            str += res[i];
        }
        return str;
    }
};