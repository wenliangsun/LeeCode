#include <bits/stdc++.h>

using namespace std;

/**
 * 产品经理(PM)有很多好的idea，而这些idea需要程序员实现。现在有N个PM，在某个时间会想出一个 idea，
 * 每个 idea 有提出时间、所需时间和优先等级。对于一个PM来说，最想实现的idea首先考虑优先等级高的，
 * 相同的情况下优先所需时间最小的，还相同的情况下选择最早想出的，没有 PM会在同一时刻提出两个 idea。
 * 同时有M个程序员，每个程序员空闲的时候就会查看每个PM尚未执行并且最想完成的一个idea,
 * 然后从中挑选出所需时间最小的一个idea独立实现，如果所需时间相同则选择PM序号最小的。
 * 直到完成了idea才会重复上述操作。如果有多个同时处于空闲状态的程序员，那么他们会依次进行查看idea的操作。
 * 求每个idea实现的时间。
 * 
 * 思路：生产者-消费者问题:PM生产Idea,程序员消费idea按时间状态模拟，一个生产Queue,一个待消费Queue,
 * 到了时间，把生产Queue中的idea放入待消费Queue中，如果有空闲的程序员，程序员就去取一个idea来使用，
 * 此时程序员身上带了一个倒计时的定时器。定时器归0则任务完成。这两个Queue使用优先级队列来定义，按照题目要求定义：
 * 生产Queue以创建时间作为比较器，任务Queue通过三条规则定义一个字典序。
 */

struct Idea {
    int pid;          // 读取进来的id
    int id;           // 原来想法的id
    int create;       // 创建想法的时间
    int power;        // 想法的优先级
    int need;         // 想法完成需要的时间
    int finish = -1;  //想法完成的时间节点
};

struct cmp {
    /**
     * 任务优先队列的排序规则，收拾时优先级，完成需要的时间，创建的时间
     */
    bool operator()(Idea idea1, Idea idea2) {
        if (idea1.power < idea2.power)
            return true;
        else if (idea1.power > idea2.power)
            return false;
        else {
            if (idea1.need > idea2.need)
                return true;
            else if (idea1.need < idea2.need)
                return false;
            else {
                if (idea1.create > idea2.create)
                    return true;
                else
                    return false;
            }
        }
    }
};

struct cmp2 {
    /**
     * idea 创建优先队列，按照创建时间排序
     */
    bool operator()(Idea idea1, Idea idea2) {
        return idea1.create > idea2.create;
    }
};

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    priority_queue<Idea, vector<Idea>, cmp> tq;
    priority_queue<Idea, vector<Idea>, cmp2> cq;
    vector<pair<int, int>> res;  // 记录答案
    vector<int> pgr(m);          // 记录程序员还有多少时间干完活
    for (int i = 0; i < p; i++) {
        int id, create, power, need;
        cin >> id >> create >> power >> need;
        Idea t = Idea();
        t.pid = i, t.id = id, t.create = create, t.power = power, t.need = need;
        cq.push(t);  // 重建队列
    }

    int k = 0;  // 时间
    // 两个队列都为空时，停止
    while (tq.size() || cq.size()) {
        // 将k时间创建的想法添加到任务队列
        while (cq.size() && cq.top().create == k) {
            tq.push(cq.top());
            cq.pop();
        }
        //
        int idxpgr = 0;  // 遍历每一个程序员
        while (idxpgr < pgr.size()) {
            if (pgr[idxpgr] > 0) {  // 程序员在干活
                pgr[idxpgr]--;      // 时间减一
                idxpgr++;
            } else {               //有空闲程序员
                if (!tq.size()) {  // 没有活
                    idxpgr++;
                } else {  // 有活
                    Idea idea = tq.top();
                    tq.pop();
                    idea.finish = k + idea.need;  // 计算完成的时间节点
                    res.push_back({idea.pid, idea.finish});  // 记录到答案中
                    pgr[idxpgr] = idea.need;
                }
            }
        }
        k++;
    }
    sort(res.begin(), res.end());  // 按照读取的id排序，然后输出结果
    for (int i = 0; i < res.size(); i++) cout << res[i].second << endl;
    return 0;
}
