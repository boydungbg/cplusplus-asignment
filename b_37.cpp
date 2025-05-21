#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
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
};

// Hàm chuẩn hóa ngày sinh về dạng dd/mm/yyyy
string chuanHoaNgaySinh(string ngaySinh)
{
  stringstream ss(ngaySinh);
  string ngay, thang, nam;
  getline(ss, ngay, '/');
  getline(ss, thang, '/');
  getline(ss, nam);

  if (ngay.length() == 1)
    ngay = "0" + ngay;
  if (thang.length() == 1)
    thang = "0" + thang;

  return ngay + "/" + thang + "/" + nam;
}

// Hàm so sánh để sắp xếp theo ngày sinh (già nhất đến trẻ nhất)
bool compareByNgaySinh(const NhanVien &a, const NhanVien &b)
{
  string ngaySinhA = a.ngaySinh.substr(6, 4) + a.ngaySinh.substr(3, 2) + a.ngaySinh.substr(0, 2);
  string ngaySinhB = b.ngaySinh.substr(6, 4) + b.ngaySinh.substr(3, 2) + b.ngaySinh.substr(0, 2);
  return ngaySinhA < ngaySinhB;
}

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<NhanVien> danhSachNV(N);

  for (int i = 0; i < N; i++)
  {
    NhanVien nv;
    getline(cin, nv.hoTen);         // Nhập họ tên
    getline(cin, nv.gioiTinh);      // Nhập giới tính
    getline(cin, nv.ngaySinh);      // Nhập ngày sinh
    getline(cin, nv.diaChi);        // Nhập địa chỉ
    getline(cin, nv.maSoThue);      // Nhập mã số thuế
    getline(cin, nv.ngayKyHopDong); // Nhập ngày ký hợp đồng

    // Tạo mã nhân viên
    stringstream ss;
    ss << setw(5) << setfill('0') << (i + 1);
    nv.maNV = ss.str();

    // Chuẩn hóa ngày sinh
    nv.ngaySinh = chuanHoaNgaySinh(nv.ngaySinh);

    danhSachNV[i] = nv;
  }

  // Sắp xếp danh sách nhân viên theo ngày sinh
  sort(danhSachNV.begin(), danhSachNV.end(), compareByNgaySinh);

  // In danh sách nhân viên
  for (const NhanVien &nv : danhSachNV)
  {
    cout << nv.maNV << " " << nv.hoTen << " " << nv.gioiTinh << " "
         << nv.ngaySinh << " " << nv.diaChi << " " << nv.maSoThue << " "
         << nv.ngayKyHopDong << endl;
  }

  return 0;
}