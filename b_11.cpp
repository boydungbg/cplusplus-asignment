#include <iostream>
#include <vector>
using namespace std;

// Hàm quay vòng mảng
void rotateArray(vector<int> &A, int d)
{
  int n = A.size();
  d = d % n; // Đảm bảo d không vượt quá kích thước mảng

  // Chia mảng thành hai phần và ghép lại
  vector<int> rotated(A.begin() + d, A.end());
  rotated.insert(rotated.end(), A.begin(), A.begin() + d);

  A = rotated; // Gán lại mảng đã quay
}

int main()
{
  int T; // Số lượng bộ test
  cin >> T;

  while (T--)
  {
    int n, d;
    cin >> n >> d;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
      cin >> A[i];
    }

    // Thực hiện quay vòng mảng
    rotateArray(A, d);

    // In kết quả
    for (int i = 0; i < n; i++)
    {
      cout << A[i] << " ";
    }
    cout << endl;
  }

  return 0;
}