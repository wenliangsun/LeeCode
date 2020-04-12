#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<unordered_set<int>> sets;
        for (int i = 1; i <= n; i++) {
            unordered_set<int> temp;
            temp.insert(i);
            sets.push_back(temp);
        }
        int type, x, y;
        for (int i = 0; i < m; i++) {
            cin >> type;
            if (type == 1) {
                cin >> x >> y;
            }
            cin >> x;
            if (type == 1) {
                unordered_set<int> s1;
                int index1 = -1, index2 = -1;
                for (int i = 0; i < sets.size(); i++) {
                    auto s = sets[i];
                    if (s.count(x) && s.count(y)) {
                        break;
                    }
                    if (s.count(x)) {
                        s1.insert(s.begin(), s.end());
                        int index1 = i;
                    }

                    if (s.count(y)) {
                        s1.insert(s.begin(), s.end());
                        index2 = i;
                    }
                    if (index1 != -1)
                        sets.erase(sets.begin() + index1,
                                   sets.begin() + index1 + 1);
                    if (index2 != -1)
                        sets.erase(sets.begin() + index2,
                                   sets.begin() + index2 + 1);
                }
            } else if (type == 2) {
                for (int i = 0; i < sets.size(); i++) {
                    auto s = sets[i];
                    if (s.count(x)) {
                        s.erase(x);
                    }
                }
                unordered_set<int> temp;
                temp.insert(x);
                sets.push_back(temp);
            } else if (type == 3) {
                for (int i = 0; i < sets.size(); i++) {
                    auto s = sets[i];
                    if (s.count(x)) {
                        cout << s.size() << endl;
                    }
                }
            }
        }
    }
}