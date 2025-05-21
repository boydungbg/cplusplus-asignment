#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n)
{
  if (n < 2)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// Hàm liệt kê các số có đúng 3 ước số
vector<int> numbersWithThreeDivisors(int N)
{
  vector<int> result;

  for (int i = 2; i <= sqrt(N); i++)
  {
    if (isPrime(i))
    {
      int square = i * i;
      if (square <= N)
      {
        result.push_back(square);
      }
    }
  }

  return result;
}

int main()
{
  int T; // Số lượng bộ test
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;

    vector<int> result = numbersWithThreeDivisors(N);

    // In các số có đúng 3 ước số
    for (size_t i = 0; i < result.size(); i++)
    {
      cout << result[i];
      if (i != result.size() - 1)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}