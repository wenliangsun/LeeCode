#include <bits/stdc++.h>

using namespace std;

class MaxQueue {
   public:
    deque<int> dq;
    queue<int> q;
    MaxQueue() {}

    int max_value() {
        if (dq.size())
            return dq.front();
        else
            return -1;
    }

    /**
     * 维护一个单调的双端队列
     */
    void push_back(int value) {
        while (dq.size() && dq.back() < value) dq.pop_back();
        dq.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.size()) {
            auto t = q.front();
            q.pop();
            if (t == dq.front()) dq.pop_front();
            return t;
        } else
            return -1;
    }
};