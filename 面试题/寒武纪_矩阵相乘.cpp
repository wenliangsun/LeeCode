#include <bits/stdc++.h>

using namespace std;

template <typename T>
// 原始版本
vector<vector<T>> matmul(vector<vector<T>>& A, vector<vector<T>>& B) {
    int m = A.size(), kA = A[0].size();
    int kB = B.size(), n = B[0].size();
    vector<vector<T>> res;
    if (kA != kB) return res;
    res = vector<vector<T>>(m, vector<T>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T sum = 0;
            for (int k = 0; k < kA; k++) {
                sum += A[i][k] * B[k][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
}

template <typename T>
// 优化版本
vector<vector<T>> matmul2(vector<vector<T>>& A, vector<vector<T>>& B) {
    int m = A.size(), kA = A[0].size();
    int kB = B.size(), n = B[0].size();
    vector<vector<T>> res;
    if (kA != kB) return res;
    res = vector<vector<T>>(m, vector<T>(n));
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < kA; k++) {
            T tmp = A[i][k];
            for (int j = 0; j < n; j++) {
                res[i][j] += tmp * B[k][j];
            }
        }
    }
    return res;
}

int main() {
    // vector<vector<double>> A = {{1, 2}, {3, 4}};
    // vector<vector<double>> B = {{5, 6}, {7, 8}};

    vector<vector<int>> A(1000, vector<int>(1000));
    vector<vector<int>> B(1000, vector<int>(1000));

    clock_t start, end;
    start = clock();
    vector<vector<int>> res = matmul(A, B); // 21671s
    vector<vector<int>> res = matmul2(A, B); // 11719s
    end = clock();
    // if (!res.size())  // 既然函数里面写了处理异常的代码，在使用的时候就要监听
    //     cout << "Error" << endl;
    // else {
    //     int m = res.size(), n = res[0].size();
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             cout << res[i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    cout << (double)(end - start) << "s" << endl;
    return 0;
}