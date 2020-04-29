#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,
 * 相同成绩,都按先录入排列在前的规则处理。
 * 
 * 冒泡排序
 */

typedef pair<string, int> PII;

int main() {
    int n;
    while (cin >> n) {
        int type;
        cin >> type;
        vector<PII> a;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            int score;
            cin >> score;
            a.push_back({name, score});
        }
        if (type) {
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < a.size() - i - 1; j++) {
                    if (a[j].second > a[j + 1].second) {
                        auto t = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = t;
                    }
                }
            }
        } else {
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < a.size() - i - 1; j++) {
                    if (a[j].second < a[j + 1].second) {
                        auto t = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = t;
                    }
                }
            }
        }
        for (auto item : a) {
            cout << item.first << ' ' << item.second << endl;
        }
    }
    return 0;
}