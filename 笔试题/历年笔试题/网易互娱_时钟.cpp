#include <stdio.h>

#include <iostream>
using namespace std;

/**
 * 时钟
 */

int main() {
    int T;
    int HH, MM, SS;
    cin >> T;
    while (T--) {
        scanf("%d:%d:%d", &HH, &MM, &SS);
        // 如果超过正常范围，把高位置零
        if (HH >= 24) {
            HH %= 10;
        }
        if (MM >= 60) {
            MM %= 10;
        }
        if (SS >= 60) {
            SS %= 10;
        }
        printf("%02d:%02d:%02d\n", HH, MM, SS);
    }
}