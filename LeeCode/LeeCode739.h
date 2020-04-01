#include <stack>
#include <vector>

using namespace std;

/**
 * 题目739：每日温度
 */
class LeeCode739 {
   public:
    /**
     * 思路：单调栈的使用
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        stack<int> stk;
        for (int i = T.size() - 1; i >= 0; i--) {
            while (!stk.empty() && T[stk.top()] <= T[i]) {
                stk.pop();
            }
            res[i] = stk.empty() ? 0 : (stk.top() - i);
            stk.push(i);
        }
    }
};