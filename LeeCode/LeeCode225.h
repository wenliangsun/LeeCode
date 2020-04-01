#include <queue>
using namespace std;

/**
 * 题目225：用队列实现栈
 */
class MyStack {
   public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        top_elem = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size();
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        int top = q.front();
        q.pop();
        return top;
    }

    /** Get the top element. */
    int top() { return top_elem; }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }

   private:
    queue<int> q;
    int top_elem;
};
