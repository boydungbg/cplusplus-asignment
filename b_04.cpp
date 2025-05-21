#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số có cân bằng chẵn lẻ hay không
bool isBalanced(int num, int N)
{
  int evenCount = 0, oddCount = 0;

  while (num > 0)
  {
    int digit = num % 10;
    if (digit % 2 == 0)
      evenCount++;
    else
      oddCount++;
    num /= 10;
  }

  return evenCount == oddCount && (evenCount + oddCount == N);
}

int main()
{
  int N;
  cin >> N;

  if (N <= 1 || N >= 7 || N % 2 != 0)
  {
    cout << "N phải là số chẵn và nằm trong khoảng 2 < N < 7" << endl;
    return 1;
  }

  int start = pow(10, N - 1); // Số nhỏ nhất có N chữ số
  int end = pow(10, N);       // Số lớn nhất có N chữ số

  vector<int> balancedNumbers;

  for (int i = start; i < end; i++)
  {
    if (isBalanced(i, N))
    {
      balancedNumbers.push_back(i);
    }
  }

  // In kết quả, mỗi dòng 10 số
  for (size_t i = 0; i < balancedNumbers.size(); i++)
  {
    cout << balancedNumbers[i] << " ";
    if ((i + 1) % 10 == 0)
      cout << endl;
  }

  return 0;
}