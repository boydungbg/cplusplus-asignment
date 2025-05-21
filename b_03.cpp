#include <iostream>
using namespace std;

int main()
{
  int N;
  cout << "Nhập số N: ";
  cin >> N;

  if (N > 20)
  {
    cout << "N không được quá 20";
    return 1;
  }

  long long S = 0;         // Tổng S
  long long factorial = 1; // Giai thừa tạm thời

  for (int i = 1; i <= N; i++)
  {
    factorial *= i; // Tính giai thừa 1 * 2 * ... * i
    S += factorial; // Cộng vào tổng S
  }

  cout << S << endl;

  return 0;
}