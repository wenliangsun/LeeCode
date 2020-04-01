#include <iostream>

using namespace std;

/**
 * 题目461：汉明距离
 */
class LeeCode461 {
   public:
    /**
     * 思路：n&n(n-1)可以将n中的最后一个1变为0
     */
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    LeeCode461 code = LeeCode461();
    int res = code.hammingDistance(3, 4);
    cout << res << endl;
    
    return 0;
}