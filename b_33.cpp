#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm sắp xếp lại mảng theo yêu cầu
vector<int> rearrangeArray(vector<int> &A) {
    vector<int> result;
    sort(A.begin(), A.end()); // Sắp xếp mảng tăng dần

    int left = 0, right = A.size() - 1;
    while (left <= right) {
        if (right >= left) {
            result.push_back(A[right--]); // Thêm số lớn nhất
        }
        if (left <= right) {
            result.push_back(A[left++]); // Thêm số nhỏ nhất
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T; // Số lượng bộ test
    while (T--) {
        int n;
        cin >> n; // Số phần tử của mảng
        vector<int> A(n);

        // Nhập mảng
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        // Sắp xếp lại mảng
        vector<int> result = rearrangeArray(A);

        // In kết quả
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}