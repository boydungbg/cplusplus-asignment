#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm phân tích các ước số nguyên tố của N
vector<long long> primeFactors(long long N) {
    vector<long long> factors;

    // Kiểm tra số 2
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // Kiểm tra các số lẻ từ 3 trở đi
    for (long long i = 3; i <= sqrt(N); i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // Nếu N là số nguyên tố lớn hơn 2
    if (N > 2) {
        factors.push_back(N);
    }

    return factors;
}

int main() {
    int T; // Số lượng bộ test
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        vector<long long> factors = primeFactors(N);

        // In các ước số nguyên tố
        for (size_t i = 0; i < factors.size(); i++) {
            cout << factors[i];
            if (i != factors.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}