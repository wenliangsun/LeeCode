#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<string> res;
    while (getline(cin, s)) {
        while (s.size() >= 8) {
            cout << s.substr(0, 8) << endl;
            s = s.substr(8);
        }
        cout << s.append(8 - s.size(), '0') << endl;
    }
}