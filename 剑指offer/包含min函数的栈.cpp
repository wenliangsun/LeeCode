#include <bits/stdc++.h>

using namespace std;

class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> m;
    MinStack() {}

    void push(int x) {
        data.push(x);
        if (m.empty() || x < m.top())
            m.push(x);
        else
            m.push(m.top());
    }

    void pop() {
        auto t = data.top();
        data.pop();
        m.pop();
    }

    int top() { return data.top(); }

    int min() { return m.top(); }
};