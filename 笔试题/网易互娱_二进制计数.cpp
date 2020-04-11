#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 题目：将一组数按照二进制表示时1的数量进行分组，返回组数。
 * 1
 * 5
 * 8 3 5 7 2
 * 输出
 * 3
 *
 * 思路：利用集合去除重复的元素  利用 num&(num-1)统计二进制数中的1的个数
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> n;
            s.insert(n & (n - 1));
        }
        cout << s.size() << endl;
    }
}
