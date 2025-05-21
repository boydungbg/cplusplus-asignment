#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm tìm số lớn nhất nhỏ hơn N với một phép đổi chỗ
string findLargestSmaller(string N) {
    int n = N.size();

    // Duyệt từ phải sang trái để tìm vị trí đầu tiên mà N[i] > N[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (N[i] > N[i + 1]) {
            // Tìm chữ số lớn nhất bên phải N[i] nhưng nhỏ hơn N[i]
            int maxIdx = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (N[j] < N[i] && N[j] > N[maxIdx]) {
                    maxIdx = j;
                }
            }

            // Đổi chỗ N[i] với N[maxIdx]
            swap(N[i], N[maxIdx]);

            // Sắp xếp các chữ số bên phải i theo thứ tự giảm dần
            sort(N.begin() + i + 1, N.end(), greater<char>());

            return N;
        }
    }

    // Nếu không tìm được số nhỏ hơn, trả về "Không có phép đổi chỗ"
    return "-1";
}

int main() {
    string N;
    cin >> N;

    // Tìm số lớn nhất nhỏ hơn N
    string result = findLargestSmaller(N);

    // In kết quả
    if (result == "-1") {
        cout << "Khong co phep doi cho" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}