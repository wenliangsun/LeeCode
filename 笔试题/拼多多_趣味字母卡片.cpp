#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 拼多多题目： 有一副卡片，a-z,A-Z，从其中抽取N张排成一个序列，
 * 现在删除重复的字符，输出删除后字典序最小的字符串的首字母。
 * 注意：字母不区分大小写
 */

int main() {
    string str;
    cin >> str;
    // 所有字母变成小写
    for (auto &c : str) {
        c = tolower(c);
    }
    // 从小到大将字母当作第一个字母
    for (char c = 'a'; c <= 'z'; c++) {
        int index = 0;
        // 从字符串中寻找字母
        while (index < str.size() && str[index] != c) {
            index++;
        }
        int k = index;
        unordered_set<char> hash;
        // 将当前字母之后的放在hash表中
        for (int i = index + 1; i < str.size(); i++) {
            hash.insert(str[i]);
        }
        bool can = true;
        // 判断当前字母前面的字母能否消除
        for (int i = 0; i < index; i++) {
            if (!hash.count(str[i])) {
                can = false;
                break;
            }
        }
        // 如果能，输出当前字符
        if (can) {
            cout << str[index] << endl;
            break;
        }
    }
    return 0;
}