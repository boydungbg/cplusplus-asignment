#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> extractDigits(const vector<long long>& A) {
    set<int> digits; // Sử dụng set để lưu các chữ số duy nhất

    for (long long num : A) {
        while (num > 0) {
            digits.insert(num % 10); // Lấy chữ số cuối cùng
            num /= 10;              // Loại bỏ chữ số cuối cùng
        }
    }

    return vector<int>(digits.begin(), digits.end()); // Chuyển set thành vector
}

int main() {
    int T; // Số lượng bộ test
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // Trích xuất và sắp xếp các chữ số
        vector<int> result = extractDigits(A);

        // In kết quả
        for (int digit : result) {
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}