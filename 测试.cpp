#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string num;
    while (cin >> num) {
        int res = 0;
        if (num[0] > '1') {
            res += pow(2, num.size()) - 1;
        } else {
            for (int i = 0; i < num.size(); i++) {
                if (num[i] == '0')
                    continue;
                else if (num[i] == '1')
                    res += pow(2, num.size() - i - 1);
                else {
                    res += pow(2, num.size() - i) - 1;
                    break;
                }
            }
        }
        cout << res << endl;
    }
}