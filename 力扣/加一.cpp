#include <stack>
#include <vector>

using namespace std;

/**
 * 题目66：加1
 */
class LeeCode66 {
   public:
    /**
     * 思路：利用栈数据结构
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if (digits.size() == 0) {
            return res;
        }
        stack<int> stk;
        int carry = 0;
        int len = digits.size() - 1;
        int sum = (digits[len] + carry + 1) > 9 ? 0 : (digits[len] + carry + 1);
        carry = (digits[len] + carry + 1) > 9 ? 1 : 0;
        stk.push(sum);
        for (int i = len - 1; i >= 0; i--) {
            sum = (digits[i] + carry) > 9 ? 0 : (digits[i] + carry);
            carry = (digits[i] + carry) > 9 ? 1 : 0;
            stk.push(sum);
        }
        if (carry != 0) {
            stk.push(carry);
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }

    /**
     * 注意考虑了只加1，进位的情况很少，设计很巧妙！！！
     */
    vector<int> plusOne2(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            // 如果没有进位，直接返回
            if (digits[i] != 0) {
                return digits;
            }
        }
        //此时情况为: 9,99,999,...
        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};