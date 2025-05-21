#include <iostream>
#include <vector>
using namespace std;

int findSmallestMissingPositive(vector<int> &A)
{
  int n = A.size();

  // Đưa các số vào đúng vị trí của chúng
  for (int i = 0; i < n; i++)
  {
    while (A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
    {
      swap(A[i], A[A[i] - 1]);
    }
  }

  // Tìm số nguyên dương nhỏ nhất không có mặt
  for (int i = 0; i < n; i++)
  {
    if (A[i] != i + 1)
    {
      return i + 1;
    }
  }

  return n + 1; // Nếu tất cả các số từ 1 đến n đều có mặt
}

int main()
{
  int T; // Số lượng bộ test
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
      cin >> A[i];
    }

    // Tìm số nguyên dương nhỏ nhất không có mặt trong mảng
    cout << findSmallestMissingPositive(A) << endl;
  }

  return 0;
}