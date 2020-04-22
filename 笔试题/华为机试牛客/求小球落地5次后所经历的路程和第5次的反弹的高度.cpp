#include <iostream>

using namespace std;

/**
 * 假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下,
 * 求它在第5次落地时，共经历多少米?第5次反弹多高？
 */

int main() {
    int n;
    while (cin >> n) {
        float path = 0;
        float h = n;
        for (int i = 0; i < 5; i++) {
            path += h + h / 2;
            h /= 2;
        }
        cout << path - h << endl;
        cout << h << endl;
    }
}