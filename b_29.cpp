#include <iostream>
#include <string>
using namespace std;

// Hàm tính tổng các số có trong xâu
int sumOfNumbersInString(const string &S)
{
  int sum = 0;
  int currentNumber = 0;
  bool inNumber = false;

  for (char c : S)
  {
    if (isdigit(c))
    {
      // Nếu ký tự là chữ số, thêm vào số hiện tại
      currentNumber = currentNumber * 10 + (c - '0');
      inNumber = true;
    }
    else
    {
      // Nếu ký tự không phải là chữ số, cộng số hiện tại vào tổng
      if (inNumber)
      {
        sum += currentNumber;
        currentNumber = 0;
        inNumber = false;
      }
    }
  }

  // Cộng số cuối cùng nếu có
  if (inNumber)
  {
    sum += currentNumber;
  }

  return sum;
}

int main()
{
  string S;
  getline(cin, S); // Nhập xâu ký tự

  // Tính tổng các số trong xâu
  int result = sumOfNumbersInString(S);

  // In kết quả
  cout << result << endl;

  return 0;
}