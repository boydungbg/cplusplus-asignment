#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countRepeatedElements(const vector<int>& A) {
    unordered_map<int, int> freq; // Bảng đếm tần suất xuất hiện của các phần tử
    int count = 0;

    // Đếm tần suất xuất hiện của từng phần tử
    for (int num : A) {
        freq[num]++;
    }

    // Đếm số phần tử bị lặp lại (tần suất > 1)
    for (const auto& pair : freq) {
        if (pair.second > 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int T; // Số lượng bộ test
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        // Đếm số phần tử bị lặp lại
        cout << countRepeatedElements(A) << endl;
    }

    return 0;
}