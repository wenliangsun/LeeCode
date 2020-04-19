#include <iostream>
#include <string>

using namespace std;

/**
 * 开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。
 * 从（0,0）点开始移动，从输入字符串里面读取一些坐标，
 * 并将最终输入结果输出到输出文件里面。
 */

int main() {
    string s;
    while (getline(cin, s)) {
        int pos = s.find(';');
        int x = 0, y = 0;
        while (pos != s.npos) {
            string temp = s.substr(0, pos);
            s = s.substr(pos + 1);
            pos = s.find(';');
            if (temp.size() <= 1) continue;
            char c = temp[0];
            int i;
            for (i = 1; i < temp.size(); i++) {
                if (temp[i] < '0' && temp[i] > '9') {
                    break;
                }
            }
            if (i != temp.size()) continue;
            int d = stoi(temp.substr(1));
            if (c == 'A' || c == 'a') {
                x -= d;
            } else if (c == 'W' || c == 'w') {
                y += d;
            } else if (c == 'D' || c == 'd') {
                x += d;
            } else if (c == 'S' || c == 's') {
                y -= d;
            } else {
                continue;
            }
        }
        cout << x << ',' << y << endl;
    }
    return 0;
}