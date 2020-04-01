#include <string>

using namespace std;

/**
 * 题目67：二进制求和
 */
class LeeCode67 {
   public:
    string addBinary(string a, string b) {
        string res = "";
        if (a.empty() && b.empty()) {
            return res;
        } else if (a.empty()) {
            return b;
        } else if (b.empty()) {
            return a;
        }
        int i, j;
        int carry = 0;
        // 注意这儿的操作！！！ 很巧妙
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry != 0;
             i--, j--) {
            int n1 = i >= 0 ? a[i] - '0' : 0;
            int n2 = j >= 0 ? b[j] - '0' : 0;
            int temp = n1 + n2 + carry;
            int sum = temp % 2;
            cout << sum << endl;
            carry = temp / 2;
            res = to_string(sum) + res;
        }
        return res;
    }
};
