#include <iostream>
#include <vector>
using namespace std;

// Hàm quay ma trận theo chiều kim đồng hồ
void rotateMatrix(vector<vector<int> > &matrix, int n, int m)
{
  int top = 0, bottom = n - 1, left = 0, right = m - 1;
  while (top < bottom && left < right)
  {
    // Lưu giá trị hàng đầu tiên
    int prev = matrix[top + 1][left];
    // Di chuyển hàng trên cùng
    for (int i = left; i <= right; i++)
    {
      int temp = matrix[top][i];
      matrix[top][i] = prev;
      prev = temp;
    }
    top++;
    // Di chuyển cột bên phải
    for (int i = top; i <= bottom; i++)
    {
      int temp = matrix[i][right];
      matrix[i][right] = prev;
      prev = temp;
    }
    right--;
    // Di chuyển hàng dưới cùng
    for (int i = right; i >= left; i--)
    {
      int temp = matrix[bottom][i];
      matrix[bottom][i] = prev;
      prev = temp;
    }
    bottom--;
    // Di chuyển cột bên trái
    for (int i = bottom; i >= top; i--)
    {
      int temp = matrix[i][left];
      matrix[i][left] = prev;
      prev = temp;
    }
    left++;
  }
}

int main()
{
  int T;
  cin >> T; // Số lượng bộ test
  while (T--)
  {
    int n, m;
    cin >> n >> m; // Số hàng và số cột của ma trận
    vector<vector<int> > matrix(n, vector<int>(m));
    // Nhập ma trận
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> matrix[i][j];
      }
    }
    // Quay ma trận
    rotateMatrix(matrix, n, m);
    // In ma trận sau khi quay
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << matrix[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}