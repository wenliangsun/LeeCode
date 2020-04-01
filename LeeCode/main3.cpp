#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "LeeCode121.h"
#include "LeeCode122.h"
#include "LeeCode123.h"

using namespace std;

int main() {
    // LeeCode121 coder121 = LeeCode121();
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // int res = coder121.maxProfit2(prices);
    // cout << res << endl;

    // LeeCode122 coder122 = LeeCode122();
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // int res = coder122.maxProfit(prices);
    // cout << res << endl;

    LeeCode123 coder123 = LeeCode123();
    vector<int> prices = {1, 2, 3, 4, 5};
    int res = coder123.maxProfit(prices);
    cout << res << endl;

    return 0;
}