#include <iostream>
#include <vector>

using namespace std;

/**
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11

直接找规律
 */

int main() {
    int n;
    while (cin >> n) {
        int base = 1;
        for (int i = 1; i <= n; i++) {
            cout << base;
            int tmp = base;
            for (int j = i + 1; j <= n; j++) {
                tmp += j;
                cout << tmp << ' ';
            }
            base += i;
            cout << endl;
        }
    }
    return 0;
}