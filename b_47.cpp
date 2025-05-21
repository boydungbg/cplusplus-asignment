#include <iostream>
#include <string>
using namespace std;

// Hàm xử lý xâu S để loại bỏ các xâu con "100" và tìm độ dài lớn nhất bị loại bỏ
int findMaxRemovedLength(string S)
{
  int maxLength = 0;
  string stack = "";

  for (char c : S)
  {
    stack += c;
    // Nếu phát hiện xâu con "100", loại bỏ nó
    if (stack.size() >= 3 && stack.substr(stack.size() - 3) == "100")
    {
      stack.erase(stack.size() - 3); // Loại bỏ "100"
      maxLength += 3;                // Cộng độ dài bị loại bỏ
    }
  }

  return maxLength;
}

int main()
{
  int T;
  cin >> T;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập T

  while (T--)
  {
    string S;
    getline(cin, S); // Nhập xâu nhị phân

    // Tìm độ dài lớn nhất của xâu con bị loại bỏ
    int result = findMaxRemovedLength(S);

    // In kết quả
    cout << result << endl;
  }

  return 0;
}