#include <iostream>
#include <string>
using namespace std;

void findSmallestAndLargest(int m, int s) {
    // Trường hợp không thể tạo số
    if (s == 0 && m > 1 || s > 9 * m) {
        cout << "-1 -1" << endl;
        return;
    }

    // Tìm số lớn nhất
    string largest = "";
    int sum = s;
    for (int i = 0; i < m; i++) {
        if (sum >= 9) {
            largest += '9';
            sum -= 9;
        } else {
            largest += (char)(sum + '0');
            sum = 0;
        }
    }

    // Tìm số bé nhất
    string smallest = largest;
    reverse(smallest.begin(), smallest.end());
    if (smallest[0] == '0') {
        for (int i = m - 1; i >= 0; i--) {
            if (smallest[i] != '0') {
                smallest[i]--;
                smallest[0] = '1';
                break;
            }
        }
    }

    cout << smallest << " " << largest << endl;
}

int main() {
    int m, s;
    cin >> m >> s;

    findSmallestAndLargest(m, s);

    return 0;
}