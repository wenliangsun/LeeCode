#include <stack>
using namespace std;

/**
 * 题目232：用栈实现队列
 */
class MyQueue {
   public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { s1.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        s2.pop();
        return top;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() { return s1.empty() && s2.empty(); }

   private:
    stack<int> s1;
    stack<int> s2;
};
