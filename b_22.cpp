#include <iostream>
#include <algorithm> // Để sử dụng hàm __gcd
using namespace std;

// Hàm tự định nghĩa để tìm ước chung lớn nhất (GCD)
long long gcd(long long a, long long b)
{
  while (b != 0)
  {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Khai báo class Phân số
class PhanSo
{
private:
  long long tuSo;  // Tử số
  long long mauSo; // Mẫu số

public:
  // Hàm khởi tạo
  PhanSo(long long tu, long long mau)
  {
    tuSo = tu;
    mauSo = mau;
  }

  // Hàm rút gọn phân số
  void rutGon()
  {
    long long gcdValue = gcd(tuSo, mauSo); // Tìm ước chung lớn nhất
    tuSo /= gcdValue;
    mauSo /= gcdValue;
  }

  // Hàm xuất phân số
  void hienThi()
  {
    cout << tuSo << "/" << mauSo << endl;
  }
};

int main()
{
  long long tu, mau;

  // Nhập tử số và mẫu số
  cin >> tu >> mau;

  // Tạo đối tượng Phân số
  PhanSo ps(tu, mau);

  // Rút gọn phân số
  ps.rutGon();

  // Hiển thị phân số tối giản
  ps.hienThi();

  return 0;
}