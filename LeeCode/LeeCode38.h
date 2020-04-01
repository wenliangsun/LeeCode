#include <string>

using namespace std;

/**
 * 题目38：外观数列
 */
class LeeCode38 {
   public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        string res = "1";
        string temp;
        for (int i = 2; i <= n; i++) {
            temp = res;  // 上一次的描述
            res = "";    // 这一次的描述
            for (int j = 0; j < temp.size();) {
                int count = 0;  // 统计出现的次数
                int index = j;  // 记录当前的索引以统计出现的次数
                while (index < temp.size() && temp[index] == temp[j]) {
                    count++;
                    index++;
                }
                // 拼接字符串
                res += to_string(count) + temp[j];
                // 更新索引
                j = index;
            }
        }
        return res;
    }
};