#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

// Khai báo cấu trúc Nhân Viên
struct NhanVien
{
  string maNV;
  string hoTen;
  string gioiTinh;
  string ngaySinh;
  string diaChi;
  string maSoThue;
  string ngayKyHopDong;

  // Chồng toán tử nhập >>
  friend istream &operator>>(istream &is, NhanVien &nv)
  {
    getline(is, nv.hoTen);         // Nhập họ tên
    getline(is, nv.gioiTinh);      // Nhập giới tính
    getline(is, nv.ngaySinh);      // Nhập ngày sinh
    getline(is, nv.diaChi);        // Nhập địa chỉ
    getline(is, nv.maSoThue);      // Nhập mã số thuế
    getline(is, nv.ngayKyHopDong); // Nhập ngày ký hợp đồng
    return is;
  }

  // Chồng toán tử xuất <<
  friend ostream &operator<<(ostream &os, const NhanVien &nv)
  {
    os << nv.maNV << " " << nv.hoTen << " " << nv.gioiTinh << " "
       << nv.ngaySinh << " " << nv.diaChi << " " << nv.maSoThue << " "
       << nv.ngayKyHopDong;
    return os;
  }
};

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<NhanVien> danhSachNV(N);

  for (int i = 0; i < N; i++)
  {
    cin >> danhSachNV[i]; // Nhập thông tin nhân viên

    // Tạo mã nhân viên
    stringstream ss;
    ss << setw(5) << setfill('0') << (i + 1);
    danhSachNV[i].maNV = ss.str();
  }

  // In danh sách nhân viên
  for (const NhanVien &nv : danhSachNV)
  {
    cout << nv << endl;
  }

  return 0;
}