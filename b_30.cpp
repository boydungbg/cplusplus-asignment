#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm xử lý xâu ký tự
string processString(const string &S)
{
  string letters = ""; // Lưu các ký tự từ 'A' đến 'Z'
  int digitSum = 0;    // Tổng các chữ số

  for (char c : S)
  {
    if (isalpha(c) && isupper(c))
    {
      // Nếu ký tự là chữ cái in hoa, thêm vào chuỗi letters
      letters += c;
    }
    else if (isdigit(c))
    {
      // Nếu ký tự là chữ số, cộng vào tổng
      digitSum += (c - '0');
    }
  }

  // Sắp xếp các ký tự trong letters theo thứ tự alphabet
  sort(letters.begin(), letters.end());

  // Nối tổng các chữ số vào cuối chuỗi letters
  letters += to_string(digitSum);

  return letters;
}

int main()
{
  string S;
  getline(cin, S); // Nhập xâu ký tự

  // Xử lý xâu và in kết quả
  cout << processString(S) << endl;

  return 0;
}