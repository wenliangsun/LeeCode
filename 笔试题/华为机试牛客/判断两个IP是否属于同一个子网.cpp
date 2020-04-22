#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string s, char c) {
    s += c;
    vector<int> res;
    int pos = s.find(c);
    while (pos != s.npos) {
        string tmp = s.substr(0, pos);
        int t = stoi(tmp);
        if (t >= 0 && t <= 255) res.push_back(t);
        s = s.substr(pos + 1);
        pos = s.find(c);
    }
    return res;
}

int main() {
    string m, p1, p2;
    while (cin >> m >> p1 >> p2) {
        vector<int> mask, ip1, ip2;
        mask = split(m, '.');
        ip1 = split(p1, '.');
        ip2 = split(p2, '.');
        bool flag = true;
        if (mask.size() == 4 && ip1.size() == 4 && ip2.size() == 4) {
            for (int i = 0; i < mask.size(); i++) {
                if (ip1[i] & mask[i] != ip2[i] & mask[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << 0 << endl;
            else
                cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}