#include <iostream>
using namespace std;

int main()
{
  int T; // Số bộ test
  cout << "Nhập số bộ test: ";
  cin >> T;

  if (T > 10)
  {
    cout << "Số bộ test không được quá 10";
    return 1;
  }

  while (T--)
  {
    char ch;
    cin >> ch;

    // Kiểm tra và chuyển đổi chữ hoa/thường
    if (ch >= 'a' && ch <= 'z')
    {
      ch = ch - 'a' + 'A'; // Chuyển chữ thường thành chữ hoa
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch - 'A' + 'a'; // Chuyển chữ hoa thành chữ thường
    }

    cout << ch << endl;
  }

  return 0;
}