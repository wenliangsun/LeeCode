#include <iostream>
#include <string>

using namespace std;

/**
 * 假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，
 * 如果我们把该编码按字典序排序，形成一个数组如下：
 * a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …,
 * yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。
 *  编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
 *
 * 长度为4时，25*25*25
 * 长度为3时，25*25
 * 长度为2时，25
 * 长度为1时，1
 *
 * 所以以a打头的一块有(25*25*25+25*25+25+1)种
 *
 * 所以计算的时候是： eg: baca
 *
 * 第一位 b: res += (b-a)*(25*25*25+25*25+25+1)
 * 第二位 a: res += (a-a)*(25*25+25+1)+1
 * 第三位 c: res += (c-a)*(25+1)+1
 * 第四位 a: res += (a-a)*(1)+1
 */

typedef long long LL;

const int N1 = 1, N2 = 25 + N1, N3 = 25 * 25 + N2, N4 = 25 * 25 * 25 + N3;

int f[4] = {N4, N3, N2, N1};

int main() {
    string s;
    while (cin >> s) {
        LL res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += (s[i] - 'a') * f[i];
            if (i) res += 1;
        }
        cout << res << endl;
    }
}