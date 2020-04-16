#include <string.h>

#include <iostream>

using namespace std;

const int N = 100010;

char s[N];

int main() {
    cin >> s;
    int i = 0, j;
    bool found = false;
    while (s[i]) {
        j = i + 1;
        while (s[i] == s[j] && s[j] == s[j + 1]) {
            j++;
            found = true;
        }
        if (found) {
            strcpy(s + i, s + j + 1);
            if (i != 0) {
                i = 0;
            }
            found = false;
        } else {
            i++;
        }
    }
    cout << s << endl;
}