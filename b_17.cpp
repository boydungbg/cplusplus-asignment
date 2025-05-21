#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long countSubstrings(const string& S) {
    vector<long long> freq(26, 0); // Mảng đếm tần suất các ký tự (a-z)
    long long count = 0;

    // Đếm tần suất xuất hiện của từng ký tự
    for (char c : S) {
        freq[c - 'a']++;
    }

    // Tính số xâu con có ký tự đầu và ký tự cuối giống nhau
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            count += (freq[i] * (freq[i] + 1)) / 2; // Công thức tổ hợp
        }
    }

    return count;
}

int main() {
    int T; // Số lượng bộ test
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        // Đếm và in kết quả
        cout << countSubstrings(S) << endl;
    }

    return 0;
}