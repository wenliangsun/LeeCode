#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 阿里 题目描述：给你一串01组成的字符串，可以选择一个位置进行翻转，即0变1,1变0，
 * 同时与该位置相邻的位置也要进行翻转 如 11011 在0的位置翻转变为10101，
 * 问给定一个这样的串，最少经过多少次翻转可以变成全0串，如果变不成输出NO。
 * "01" --> NO
 * "011" --> 1
 * 思路：每一个位置要么不翻转，要么只翻转一次，翻转两次相当于没翻转
 * 然后深度优先搜索。
 * LeeCode1284
 */

class Solution {
   public:
    int reverse(string s) {
        if (s == "1") {
            return 1;
        } else if (s == "0") {
            return 0;
        }
        int count = 0;
        if (helper(s, 0, 0)) {
            return res;
        } else {
            return -1;
        }
    }

   private:
    int res = 0;  // 记录翻转次数
    bool helper(string s, int index, int count) {
        string temp(s.size(), '0');  // 和s等长的全0串
        if (s == temp) {  // 如果等于全0串，则记录翻转次数，返回
            res = count;
            return true;
        }
        // 如果翻转的位置已经到达s的末尾，则不能翻转成全0串
        if (index == s.size()) {
            return false;
        }
        // 递归，要么翻转当前位置，要么不翻转当前位置
        // 翻转当前位置 调用reverse函数翻转，计数器count+1，并移动到下一个位置
        // 若不翻转，移到下一个位置，
        return helper(reverse(s, index), index + 1, count + 1) ||
               helper(s, index + 1, count);
    }

    // 翻转字符串中的每一个位置，注意边界情况
    string reverse(string s, int index) {
        int n = s.size() - 1;
        if (index == 0) {
            s[0] = s[0] == '0' ? '1' : '0';
            s[1] = s[1] == '0' ? '1' : '0';
        } else if (index == n) {
            s[n] = s[n] == '0' ? '1' : '0';
            s[n - 1] = s[n - 1] == '0' ? '1' : '0';
        } else if (index > 0 && index < n) {
            s[index - 1] = s[index - 1] == '0' ? '1' : '0';
            s[index] = s[index] == '0' ? '1' : '0';
            s[index + 1] = s[index + 1] == '0' ? '1' : '0';
        }
        return s;
    }
};

int main() {
    Solution solu = Solution();
    string str = "011111";
    int res = solu.reverse(str);
    if (res != -1) {
        cout << res << endl;
    } else {
        cout << "No";
    }
    return 0;
}