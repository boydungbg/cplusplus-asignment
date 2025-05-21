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
    int N;
    cin >> N;

    int S = N * (N + 1) / 2;

    cout << S << endl;
  }

  return 0;
}