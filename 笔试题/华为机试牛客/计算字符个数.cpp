#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    char a;
    cin >> a;
    int cnt = 0;
    for (auto c : s) {
        if (c == a || c + 32 == a || c - 32 == a) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}