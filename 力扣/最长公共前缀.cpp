#include <string>
#include <vector>

using namespace std;

/**
 * 题目14：最长公共前缀
 */
class LeeCode14 {
   public:
    /**
     * 思路：直接依次扫描
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string temp = strs[0];
        int index = 0;
        for (index; index < temp.size(); index++) {
            for (int i = 0; i < strs.size(); i++) {
                if (temp[index] != strs[i][index]) {
                    return temp.substr(0, index);
                }
            }
        }
        return temp;
    }
};