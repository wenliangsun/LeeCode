#include <iostream>
#include <map>

using namespace std;

/**
 * 数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，
 * 即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
 */

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int k, v;
        cin >> k >> v;
        if (mp.count(k)) {
            mp[k] += v;
        } else {
            mp[k] = v;
        }
    }
    map<int, int>::iterator it;
    for (auto it = mp.begin(); it != mp.end();) {
        auto temp = *it;
        cout << temp.first << ' ' << temp.second << endl;
        it++;
    }
}