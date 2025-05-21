#include <iostream>
#include <vector>
using namespace std;

// Hàm tính tích chập của ma trận A và B
vector<vector<int> > convolution(const vector<vector<int> > &A, const vector<vector<int> > &B, int N, int M)
{
  vector<vector<int> > result(N, vector<int>(N, 0)); // Ma trận kết quả

  // Duyệt qua từng "khung cửa sổ" trên ma trận A
  for (int i = 0; i <= N - M; i += M)
  {
    for (int j = 0; j <= N - M; j += M)
    {
      // Tính tích chập cho khung cửa sổ hiện tại
      for (int x = 0; x < M; x++)
      {
        for (int y = 0; y < M; y++)
        {
          result[i + x][j + y] += A[i + x][j + y] * B[x][y];
        }
      }
    }
  }

  return result;
}

int main()
{
  int N, M;

  // Nhập kích thước ma trận A
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }

  // Nhập kích thước ma trận B
  cin >> M;
  vector<vector<int> > B(M, vector<int>(M));
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> B[i][j];
    }
  }

  // Tính tích chập
  vector<vector<int> > result = convolution(A, B, N, M);

  // In ma trận kết quả
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}