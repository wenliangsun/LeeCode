#include <stack>

using namespace std;
/**
 * 题目9：回文数
 * 判断一个整数是否是回文数。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 */
class LeeCode09 {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        stack<int> stk;
        while (x) {
            stk.push(x % 10);
            x /= 10;
        }
        while (temp) {
            if (stk.top() == temp % 10) {
                stk.pop();
                temp /= 10;
            } else {
                return false;
            }
        }
        return true;
    }
};
