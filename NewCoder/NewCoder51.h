#include <vector>

using namespace std;

/**
 * 题目51：构建乘积数组
 */
class NewCoder51 {
   public:
    /**
     * 思路：分两部分，左侧部分，右侧部分，自己动手列一些之后发现规律！！！
     */
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len, 0);
        if (A.empty()) {
            return B;
        }
        B[0] = 1;
        for (int i = 1; i < len; i++) { // 计算左侧
            B[i] = B[i - 1] * A[i - 1];
        }
        int temp = 1;
        for (int i = len - 2; i >= 0; i--) { // 计算右侧
            temp *= A[i + 1]; 
            B[i] *= temp; // 将右侧乘的结果乘给左侧
        }
        return B;
    }
};