#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int r = s.size() - 1;
        while (r > 0 && s[r] == ' ') r--;
        int l = r;
        while (l > 0 && s[l] != ' ') l--;
        cout << r - l << endl;
    }
    return 0;
}