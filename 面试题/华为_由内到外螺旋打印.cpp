#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int m = max(abs(x), abs(y));
    int rightBottom = m * m * 4 - 2 * m + 1;
    int value = 0;
    if (x == -m) {
        value = rightBottom + 2 * m + m - y;
    } else if (y == m) {
        value = rightBottom + m - x;
    } else if (y == -m) {
        value = rightBottom + 4 * m + x + m;
    } else if (x == m) {
        value = rightBottom - (m - y);
    }
    cout << value << endl;
    return 0;
}