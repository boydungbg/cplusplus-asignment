#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    // Kiểm tra xem ký tự có phải nguyên âm hay không
    c = tolower(c); // Chuyển ký tự về dạng chữ thường
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    string S;
    cin >> S;

    string result = "";

    for (char c : S) {
        if (!isVowel(c)) {
            result += '.';
            result += tolower(c); // Chuyển ký tự về chữ thường
        }
    }

    cout << result << endl;

    return 0;
}