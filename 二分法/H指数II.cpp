#include <vector>

using namespace std;

/**
 * 给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照升序排列
 * 编写一个方法，计算出研究者的 h 指数。
 * h 指数的定义: “h 代表“高引用次数”（high citations），
 * 一名科研人员的 h 指数是指他（她）的 （N 篇论文中）至多有
 * h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h
 * 次。）"
 * 
 * 思路：
 * 
 */

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() || !citations.back()) return 0;
        int l = 0, r = citations.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (citations[mid] >= citations.size() - mid)
                r = mid;
            else
                l = mid + 1;
        }
        return citations.size() - l;
    }
};