#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    // Sắp xếp mảng để tìm chênh lệch nhỏ nhất
    sort(A.begin(), A.end());

    int minDifference = INT_MAX;
    for (int i = 1; i < N; i++)
    {
      minDifference = min(minDifference, A[i] - A[i - 1]);
    }

    cout << minDifference << endl;
  }

  return 0;
}