#include <iostream>

using namespace std;

/**
 * 题目：在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，
 * 四种方向的直线连续D个数字的和里面最大的值
 */

const int N = 110;

int a[N][N];
int n, d;

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    //行最大
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            for (int k = 0; k < d; k++) {
                if (j + k > n) break;
                sum += a[i][j + k];
            }
            res = max(res, sum);
        }
    }
    // 列最大
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int k = 0; k < d; k++) {
                if (i + k > n) break;
                sum += a[i + k][j];
            }
            res = max(res, sum);
        }
    }

    // 左上到右下 最大
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            for (int k = 0; k < d; k++) {
                if (i + k > n || j + k > n) break;
                sum += a[i + k][j + k];
            }
            res = max(res, sum);
        }
    }
    // 右上到左下 注意这儿i的边界 
    for (int i = 1; i <= n - d + 1; i++) {
        for (int j = n; j > 0; j--) {
            int sum = 0;
            for (int k = 0; k < d; k++) {
                if (i + k > n || j - k < 1) break;
                sum += a[i + k][j - k];
            }
            res = max(res, sum);
        }
    }
    cout << res << endl;
}