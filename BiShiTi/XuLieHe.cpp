#include <iostream>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    for (int i = 2; i <= 100; i++) {
        if ((2 * N + i - i * i) % (2 * i) == 0) {
            int start = (2 * N + i - i * i) / (2 * i);
            for (int j = 0; j < i - 1; j++) {
                cout << start + j << " ";
            }
            cout << start + i - 1;
            return 0;
        }
    }
}