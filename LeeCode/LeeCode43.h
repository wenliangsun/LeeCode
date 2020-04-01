#include <string>

using namespace std;

/**
 * 题目43：字符串相乘
 */
class LeeCode43 {
   public:
    /**
     * 拆解计算
     * 时间复杂度：O(MN)
     * 空间复杂度：O(M+N)
     */
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string res = "0";
        // 用num2中的每一位与num1相乘
        for (int i = num2.size() - 1; i >= 0; i--) {
            string temp = "";  // 保存相乘的结果
            int carry = 0;     // 记录进位
            // 右侧补零
            for (int j = num2.size() - 1; j > i; j--) {
                temp += "0";
            }
            int n2 = num2[i] - '0';
            // 当前位与num1相乘
            for (int j = num1.size() - 1; j >= 0 || carry != 0; j--) {
                int n1 = j < 0 ? 0 : num1[j] - '0';
                int mul = (n1 * n2 + carry) % 10;
                temp = to_string(mul) + temp;
                carry = (n1 * n2 + carry) / 10;
            }
            // 相乘的结果与之前的结果相加
            res = add(temp, res);
        }
        return res;
    }

   private:
    /**
     * 两个数字字符串相加
     */
    string add(string num1, string num2) {
        string res = "";
        int carry = 0;
        for (int i = num1.size() - 1, j = num2.size() - 1;
             i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int n1 = i < 0 ? 0 : num1[i] - '0';
            int n2 = j < 0 ? 0 : num2[j] - '0';
            int sum = (n1 + n2 + carry) % 10;
            res = to_string(sum) + res;
            carry = (n1 + n2 + carry) / 10;
        }
        return res;
    }
};