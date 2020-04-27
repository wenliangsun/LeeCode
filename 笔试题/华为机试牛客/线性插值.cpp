#include <iostream>
#include <vector>

using namespace std;

/**
 * https://www.nowcoder.com/practice/91b4c0f9fa9545a582e5b38bb9f6b90e?tpId=37&tqId=21270&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=3
 */

int main() {
    int m, n;
    while (cin >> m >> n) {
        int M, N, A, B;
        cin >> M >> A;
        cout << M << ' ' << A << endl;
        for (int i = 1; i < m; i++) {
            cin >> N >> B;
            if (N == M)
                continue;
            else {
                for (int j = 1; j < N - M; j++) {
                    cout << M + j << ' ' << A + ((B - A) / (N - M)) * j << endl;
                }
                cout << N << ' ' << B << endl;
                M = N, A = B;
            }
        }
    }
    return 0;
}