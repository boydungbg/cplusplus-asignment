#include <iostream>
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
  PhanSo(long long tu = 0, long long mau = 1)
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

  // Hàm cộng hai phân số
  PhanSo operator+(const PhanSo &other)
  {
    long long tu = tuSo * other.mauSo + mauSo * other.tuSo; // Tử số
    long long mau = mauSo * other.mauSo;                    // Mẫu số
    return PhanSo(tu, mau);
  }

  // Hàm xuất phân số
  void hienThi()
  {
    cout << tuSo << "/" << mauSo << endl;
  }
};

int main()
{
  long long tu1, mau1, tu2, mau2;

  // Nhập tử số và mẫu số của hai phân số
  cin >> tu1 >> mau1 >> tu2 >> mau2;

  // Tạo hai đối tượng Phân số
  PhanSo p(tu1, mau1), q(tu2, mau2);

  // Tính tổng hai phân số
  PhanSo tong = p + q;

  // Rút gọn phân số tổng
  tong.rutGon();

  // Hiển thị phân số tổng tối giản
  tong.hienThi();

  return 0;
}