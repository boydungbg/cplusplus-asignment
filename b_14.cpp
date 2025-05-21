#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Sử dụng set để lưu các số khác nhau và tự động sắp xếp
    set<int> uniqueNumbers(A.begin(), A.end());

    // In các số khác nhau theo thứ tự tăng dần
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}