#include <iostream>
#include <vector>
using namespace std;

// Hàm in các phần tử thuộc vùng biên của ma trận
void printBoundary(const vector<vector<int> >& A, int N) {
    // In hàng đầu tiên
    for (int j = 0; j < N; j++) {
        cout << A[0][j] << " ";
    }

    // In cột cuối cùng (trừ phần tử đầu và cuối)
    for (int i = 1; i < N - 1; i++) {
        cout << A[i][N - 1] << " ";
    }

    // In hàng cuối cùng (nếu N > 1)
    if (N > 1) {
        for (int j = N - 1; j >= 0; j--) {
            cout << A[N - 1][j] << " ";
        }
    }

    // In cột đầu tiên (trừ phần tử đầu và cuối)
    for (int i = N - 2; i > 0; i--) {
        cout << A[i][0] << " ";
    }

    cout << endl;
}

int main() {
    int T; // Số lượng bộ test
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int> > A(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }

        // In các phần tử thuộc vùng biên
        printBoundary(A, N);
    }

    return 0;
}