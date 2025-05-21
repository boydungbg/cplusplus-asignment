#include <iostream>
#include <vector>
using namespace std;

void modifyMatrix(vector<vector<int> > &A, int N, int M)
{
  vector<int> row(N, 0), col(M, 0);

  // Ghi nhận các hàng và cột cần thay đổi
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (A[i][j] == 1)
      {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }

  // Thay đổi các hàng và cột
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (row[i] == 1 || col[j] == 1)
      {
        A[i][j] = 1;
      }
    }
  }
}

int main()
{
  int T; // Số lượng bộ test
  cin >> T;

  while (T--)
  {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > A(N, vector<int>(M)); // Thêm khoảng trắng giữa '>>'

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        cin >> A[i][j];
      }
    }

    // Sửa đổi ma trận
    modifyMatrix(A, N, M);

    // In kết quả
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        cout << A[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}