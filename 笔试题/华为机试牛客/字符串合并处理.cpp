#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * 将输入的两个字符串合并。
 * 对合并后的字符串进行排序，
 * 要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。
 * 这里的下标意思是字符在字符串中的位置。
 * 对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，
 * 则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。
 * 如字符为‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’；
 * 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’。
 */

// 这个映射太机智了！！！
const string helper1 = "0123456789abcdefABCDEF";
const string helper2 = "084C2A6E195D3B7F5D3B7F";

int main() {
    string s1;
    string s2;
    while (cin >> s1) {
        cin >> s2;
        string s = s1 + s2;
        string odd = "";
        string even = "";
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                even += s[i];
            } else {
                odd += s[i];
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        string tmp = "";
        int i = 0, j = 0;
        while (i < even.size() || j < odd.size()) {
            tmp = i >= even.size() ? tmp : tmp + even[i];
            tmp = j >= odd.size() ? tmp : tmp + odd[j];
            i++, j++;
        }
        for (int i = 0; i < tmp.size(); i++) {
            int pos = helper1.find(tmp[i]);
            if (pos != helper1.npos) tmp[i] = helper2[pos];
        }
        cout << tmp << endl;
    }
    return 0;
}