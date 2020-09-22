#include <bits/stdc++.h>

using namespace std;

/**
 * 大礼包
 */

class Solution {
   public:
    /**
     * 深搜
     * 首先考虑使用原价购买所有的物品，然后从大礼包套餐中寻找可以用的大礼包，如果大礼包中的所有物品的数量都不超过需要购买的
     * 数量，说明当前大礼包可以使用，我们使用当前大礼包，并更新还需要购买的物品数量，递归计算即可
     */
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                       vector<int>& needs) {
        int res = cnt(price, needs); // 先使用原价购买所有商品
        for (auto s : special) { // 遍历大礼包，寻找可以用的大礼包
            vector<int> cur(needs); // 把需要购买的物品数量备份
            int i = 0;
            for (i = 0; i < needs.size(); i++) {
                int diff = cur[i] - s[i];
                if (diff < 0) break; // 如果大礼包中的物品数量大于需要购买的物品数量，则当前大礼包不可用
                cur[i] = diff;
            }
            if (i == needs.size()) // 如果大礼包可以用的话
                // 当前大礼包的价钱+购买剩余数量物品的价钱
                res = min(res, s[i] + shoppingOffers(price, special, cur));
        }
        return res;
    }

    // 备忘录优化
    map<vector<int>, int> memo; // unordered_map不能使用vector<int>做键，没有vector<int>的哈希函数，可以用map来替代，map是红黑树实现的
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (memo.count(needs)) return memo[needs];
        int res = cnt(price, needs);
        for (auto s : special) {
            vector<int> cur(needs);
            int i = 0;
            for (i = 0; i < needs.size(); i++) {
                int diff = cur[i] - s[i];
                if (diff < 0) break;
                cur[i] = diff;
            }
            if (i == needs.size()) 
                res = min(res, s[i] + shoppingOffers(price, special, cur));
        }
        memo[needs] = res;
        return res;
    }

    // 计算原价购买需要的金额
    int cnt(vector<int>& price, vector<int> needs) {
        int res = 0;
        for (int i = 0; i < needs.size(); i++) {
            res += needs[i] * price[i];
        }
        return res;
    }
};