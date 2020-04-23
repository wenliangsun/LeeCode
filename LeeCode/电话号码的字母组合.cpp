#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目17：电话号码的字母组合
 */
class LeeCode17 {
   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return res;
        }
        string combStr = "";
        genCombination(combStr, digits, 0);
        return res;
    }

   private:
    vector<string> res;
    map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                           {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                           {'8', "tuv"}, {'9', "wxyz"}};
    /**
     * 思路：回溯法
     */
    void genCombination(string combStr, string digits, int curIndex) {
        // 如果数字没有了表明字符串生成完毕，则添加
        if (curIndex == digits.size()) {
            res.push_back(combStr);
        } else {
            // 否则获取当前数字对应的字符串
            string str = m[digits[curIndex]];
            // 依次遍历每一个字符中的每一个字符串
            for (int i = 0; i < str.size(); i++) {
                // 注意这儿递归函数参数的传值！！！回溯法，回溯过来不能破坏当前参数的值
                genCombination(combStr + str[i], digits, curIndex + 1);
            }
        }
    }
};