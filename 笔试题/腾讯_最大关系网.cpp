#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 有n对关系，比如A和B有关系，B和C有关系，则ABC关系。
 * 求这些关系中能构成的最大关系网中的人数。
 * 
 * 输入 n // n对关系
 * n行，每一行是一对关系
 * 
 * 输出 这些关系构建出的最大关系网中的人数
 */

typedef pair<int, int> PII;

unordered_set<int> st;

void dfs(unordered_map<int, vector<int>> mp, int k) {
    if (st.count(k)) return;
    st.insert(k);
    auto tmp = mp[k];
    for (auto i = 0; i < tmp.size(); i++) {
        dfs(mp, tmp[i]);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        unordered_map<int, vector<int>>::iterator it;
        int res = 0;
        for (it = mp.begin(); it != mp.end(); it++) {
            auto t = *it;
            st.clear();
            dfs(mp, t.first);
            int k = st.size();
            res = max(res, k);
        }
        cout << res << endl;
    }
}

作者：Mr.森.
链接：https://www.nowcoder.com/discuss/418770?type=1
来源：牛客网

from collections import defaultdict
  
T = int(input())
for i in range(T):
    graph = defaultdict(list)
    sts = set()
     
    n = int(input())
    for j in range(n):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
        sts.add(a)
        sts.add(b)
 
    res = 1
    vis = set()    #vis:全局浏览记录
    for i in sts:
        if i in vis:continue
        q = [i]     #q:队列，广度优先搜索
        vis1=set()    #vis1:该圈浏览记录
        while q:
            x = q.pop(0)
            vis.add(x)
            vis1.add(x)
            for y in graph[x]:
                if not y in vis1:
                    q.append(y)
        res = max(res, len(vis1))
    print(res)