#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int cntE = 0, cntK = 0, cntS = 0, cntO = 0;
        for (auto c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                cntE++;
            else if (c == ' ')
                cntK++;
            else if (c >= '0' && c <= '9')
                cntS++;
            else
                cntO++;
        }
        cout << cntE << endl;
        cout << cntK << endl;
        cout << cntS << endl;
        cout << cntO << endl;
    }
}