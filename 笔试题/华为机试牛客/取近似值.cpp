#include <iostream>
using namespace std;

/**
 * 写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。
 * 如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
 */

int main() {
    float n;
    cin >> n;
    int temp = (int)n;
    temp = n - temp >= 0.5 ? temp + 1 : temp;
    cout << temp << endl;
}