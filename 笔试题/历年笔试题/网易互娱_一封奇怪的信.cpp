#include <iostream>
#include <string>

using namespace std;

/**
 * 题目：现在你需要用一台奇怪的打字机书写一封书信。信的每行只能容纳宽度为100的字符，
 * 也就是说如果写下某个字符会导致行宽超过100，那么就要另起一行书写信的内容由a-z的
 * 26个小写字母构成，而每个字母的宽度均会事先约定。例如字符宽度约定为
 * [1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5]，
 * 那么就代表'a'到'd'四个字母的宽度分别是1,2,3,4，而'e'到'z'的宽度均为5
 * 那么按照上述规则将给定内容S书写成一封信后，这封信共有几行？最后一行宽度是多少？
 * 题目链接：https://www.nowcoder.com/practice/d7764905e41a413c98900e22a9cc4ec3?tpId=98&tqId=32893&tPage=4&rp=4&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking
 */

const int Len = 100, N = 1010;

int w[26];

int main() {
    for (int i = 0; i < 26; i++) {
        cin >> w[i];
    }
    string s;
    cin >> s;
    int rows = 1;
    int temp = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = w[s[i] - 'a'];
        if (temp + c > Len) {
            temp = 0;
            rows++;
        }
        temp += c;
    }
    cout << rows << ' ' << temp << endl;
}
