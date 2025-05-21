#include <iostream>
#include <vector>
using namespace std;

// Hàm để biến mảng thành mảng đối xứng với số phép Merge ít nhất
int makeSymmetric(vector<int> &A)
{
  int n = A.size();
  int left = 0, right = n - 1;
  int mergeCount = 0;

  while (left < right)
  {
    if (A[left] == A[right])
    {
      // Nếu hai phần tử đã bằng nhau, không cần làm gì
      left++;
      right--;
    }
    else if (A[left] < A[right])
    {
      // Nếu A[left] nhỏ hơn A[right], gộp A[left] với A[left+1]
      A[left + 1] += A[left];
      left++;
      mergeCount++;
    }
    else
    {
      // Nếu A[right] nhỏ hơn A[left], gộp A[right] với A[right-1]
      A[right - 1] += A[right];
      right--;
      mergeCount++;
    }
  }

  return mergeCount;
}

int main()
{
  int n;
  cin >> n; // Số phần tử của mảng
  vector<int> A(n);

  // Nhập mảng
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  // Biến mảng thành mảng đối xứng
  int result = makeSymmetric(A);

  // In kết quả
  cout << "So phep Merge it nhat: " << result << endl;

  return 0;
}