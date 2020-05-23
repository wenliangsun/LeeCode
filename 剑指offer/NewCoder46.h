#include <list>
#include <vector>

using namespace std;

/**
 * 题目46：孩子们的游戏(圆圈中最后剩下的数字)
 */
class NewCoder46 {
   public:
    /**
     * 思路：推导出数学公式：
     * f(n,m) = [f(n-1,m)+m] % n n>=1; -1 n=0;
     * @param n
     * @param m
     */
    int LastRemaining_Solution01(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i;
        }
        return last;
    }

    /**
     * 思路：利用环形链表模拟该游戏！
     * @param n
     * @param m
     */
    int LastRemaining_Solution02(int n, int m) {
        if (n < 1 || m < 1) {
            return -1;
        }
        list<int> circle;
        for (int i = 0; i < n; i++) { // 构造循环链表
            circle.push_back(i);
        }
        list<int>::iterator current = circle.begin(); // list 只能用指针进行操作
        while (circle.size() > 1) {
            for (int i = 1; i < m; i++) { // 寻找第m个结点
                current++;
                if (current == circle.end()) { // 如果遍历到链表结点，则从头部开始
                    current = circle.begin();
                }
            }
            list<int>::iterator next = ++current; // 链表删除需要两个指针，用于指向下一个结点
            if (next == circle.end()) {
                next = circle.begin();
            }
            --current;
            cout << *current << " ";
            circle.erase(current);
            current = next;
        }
        return *current;
    }
};