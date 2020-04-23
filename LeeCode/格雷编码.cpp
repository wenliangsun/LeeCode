#include <vector>

using namespace std;

/**
 * 题目89：格雷编码
 */
class LeeCode89 {
   public:
    /**
     * 思路：动态规划
     * G(n) = '0'+G(n-1)+'1'G(n-1)'
     * 即当前格雷码是n-1基础上在前面补零(相当于不变)和 将 n-1
     * 进行镜像，然后在前面补1而得到(相当于加上2^i).
     * 时间复杂度：O(2^n)
     * 空间复杂度：O(1)
     */
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            int add = 1 << i;  // 计算要加的数
            // 倒着遍历之前的格雷码并加上需要加的数
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] + add);
            }
        }
        return res;
    }
};