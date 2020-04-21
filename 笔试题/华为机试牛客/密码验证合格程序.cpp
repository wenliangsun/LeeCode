#include <iostream>
#include <string>

using namespace std;

/**
 * 密码要求:
 * 1.长度超过8位
 * 2.包括大小写字母.数字.其它符号,以上四种至少三种
 * 3.不能有相同长度超2的子串重复
 */

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.size() <= 8)  // 第一个条件
            cout << "NG" << endl;
        else {
            int flag[4] = {0};
            for (auto c : s) {
                if (c >= 'A' && c <= 'Z')
                    flag[0] = 1;
                else if (c >= 'a' && c <= 'z')
                    flag[1] = 1;
                else if (c >= '0' && c <= '9')
                    flag[2] = 1;
                else
                    flag[3] = 1;
            }
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += flag[i];
            }
            if (sum < 3)  // 第二个条件
                cout << "NG" << endl;
            else {
                bool rep = false;
                for (int i = 0; i < s.size() - 3; i++) {
                    string temp = s.substr(i, 3);
                    int pos = s.find(temp, i + 3);
                    if (pos != s.npos) {  // 第三个条件
                        cout << "NG" << endl;
                        rep = true;
                        break;
                    }
                }
                if (!rep) {
                    cout << "OK" << endl;
                }
            }
        }
    }
    return 0;
}