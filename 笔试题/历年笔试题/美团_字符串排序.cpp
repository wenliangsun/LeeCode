#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string s1, string s2) {
    if (s1.empty())
        return true;
    else if (s2.empty())
        return false;
    else {
        if (s1.size() < s2.size()) {
            if (s1 == s2.substr(0, s1.size())) {
                return true;
            } else {
                return s1 > s2;
            }
        } else {
            if (s2 == s1.substr(0, s2.size())) {
                return false;
            } else {
                return s1 > s2;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    s += ',';
    vector<string> names;
    int pos = s.find(',');
    while (pos != s.npos) {
        string temp = s.substr(0, pos);
        names.push_back(temp);
        s = s.substr(pos + 1);
        pos = s.find(',');
    }
    sort(names.begin(), names.end(), cmp);
    for (int i = 0; i < names.size() - 1; i++) {
        cout << names[i] << ',';
    }
    cout << names.back() << endl;
}
