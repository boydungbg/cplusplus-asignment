#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b;
    cout << "Nhập hai số nguyên dương: ";
    cin >> a >> b;

    if (a > b) swap(a, b); // Đảm bảo a <= b

    cout << "Các số nguyên tố trong khoảng [" << a << ", " << b << "] là:" << endl;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}