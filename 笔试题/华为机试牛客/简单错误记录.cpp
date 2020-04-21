#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
 */

struct Note {
    string file;
    string line;
    int cnt = 1;
    bool operator==(const Note &a) {
        if (a.file == file && a.line == line)
            return true;
        else
            return false;
    }
    Note(string f, string l) : file(f), line(l){};
};

int main() {
    string s;
    vector<Note> res;
    vector<Note>::iterator it;
    while (getline(cin, s)) {
        int sp = s.find(' ');
        string lines = s.substr(sp + 1);
        while (lines[0] == ' ') lines = lines.substr(1);
        string path = s.substr(0, sp);
        string file = "";
        for (int i = 1; i <= 16; i++) {
            if (path[path.size() - i] == '\\') {
                break;
            }
            file = path[path.size() - i] + file;
        }
        Note nd = Note(file, lines);
        it = find(res.begin(), res.end(), nd);
        if (it == res.end()) {
            res.push_back(nd);
        } else {
            it->cnt++;
        }
    }
    if (res.size() > 8) {
        int n = res.size();
        for (int i = n - 8; i < n; i++) {
            cout << res[i].file << ' ' << res[i].line << ' ' << res[i].cnt
                 << endl;
        }
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].file << ' ' << res[i].line << ' ' << res[i].cnt
                 << endl;
        }
    }
    return 0;
}