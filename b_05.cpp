#include <iostream>
using namespace std;

int main()
{
  int T; // Số lượng bộ dữ liệu
  cin >> T;

  if (T > 20)
  {
    cout << "Số lượng bộ dữ liệu không được lớn hơn 20" << endl;
    return 1;
  }

  while (T--)
  {
    int X;
    cin >> X;

    // Kiểm tra xem số X có kết thúc bằng 86 hay không
    if (X % 100 == 86)
    {
      cout << 1 << endl; // Kết thúc bằng 86
    }
    else
    {
      cout << 0 << endl; // Không kết thúc bằng 86
    }
  }

  return 0;
}