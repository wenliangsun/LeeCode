#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> split(string s) {
    s += ' ';
    vector<int> res;
    int pos = s.find(' ');
    while (pos != s.npos) {
        res.push_back(stoi(s.substr(0, pos)));
        s = s.substr(pos + 1);
        pos = s.find(' ');
    }
    return res;
}

ListNode* mergeLists(vector<ListNode*>& lists) {
    auto dummy = new ListNode(-1);
    auto p = dummy;
    while (true) {
        int minV = INT_MAX;
        bool flag = true;
        int idx = 0;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] && lists[i]->val < minV) {
                minV = lists[i]->val;
                idx = i;
                flag = false;
            }
        }
        if (flag) break;
        p->next = lists[idx];
        lists[idx] = lists[idx]->next;
        p = p->next;
    }
    return dummy->next;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<ListNode*> lists;
    for (int i = 0; i < n; i++) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
        int t;
        while (cin >> t) {
            p->next = new ListNode(t);
            p = p->next;
            if (cin.get() == '\n') break;
        }
        // string s;
        // getline(cin, s);
        // vector<int> tmp = split(s);
        // for (auto t : tmp) {
        //     p->next = new ListNode(t);
        //     p = p->next;
        // }
        lists.push_back(dummy->next);
    }

    auto res = mergeLists(lists);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }
    cout << endl;
    return 0;
}