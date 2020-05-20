#include <bits/stdc++.h>

using namespace std;

bool isNum(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

int main() {
    string s;
    while (cin >> s) {
        int l = 0, r = s.size() - 1;
        bool isPalindrome = true;
        while (l < r) {
            while (isNum(s[l]) && l < r) l++;
            while (isNum(s[r]) && l < r) r--;
            if (toupper(s[l]) != toupper(s[r])) {
                isPalindrome = false;
                break;
            }
            l++, r--;
        }
        if (isPalindrome)
            cout << "yes" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}