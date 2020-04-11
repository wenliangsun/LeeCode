#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：小云正在参与开发一个即时聊天工具，他负责其中的会话列表部分。
 * 会话列表为显示为一个从上到下的多行控件，其中每一行表示一个会话，
 * 每一个会话都可以以一个唯一正整数id表示。当用户在一个会话中发送或接收信息时，
 * 如果该会话已经在会话列表中，则会从原来的位置移到列表的最上方；
 * 如果没有在会话列表中，则在会话列表最上方插入该会话。
 * 小云在现在要做的工作是测试，他会先把会话列表清空等待接收信息。
 * 当接收完大量来自不同会话的信息后，就输出当前的会话列表，以检查其中是否有bug。
 * 题目链接：https://www.nowcoder.com/practice/0f52adb3946249f9bb63d964658b2691?tpId=98&tqId=32891&tPage=4&rp=4&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking
 */

const int N = 210;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<int>::iterator it;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            it = find(a.begin(), a.end(), x);
            if (it != a.end()) {
                *it = 0;
            }
            a.push_back(x);
        }

        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] != 0) {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}