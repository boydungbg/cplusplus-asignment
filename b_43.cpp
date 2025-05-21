#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Khai báo cấu trúc Sinh Viên
struct SinhVien
{
  string maSV;
  string hoTen;
  string lop;
  string email;
};

// Hàm so sánh để sắp xếp theo mã sinh viên tăng dần
bool compareByMaSV(const SinhVien &a, const SinhVien &b)
{
  return a.maSV < b.maSV;
}

int main()
{
  vector<SinhVien> danhSachSV;
  string maSV, hoTen, lop, email;

  // Nhập danh sách sinh viên
  while (getline(cin, maSV))
  {
    SinhVien sv;
    sv.maSV = maSV;
    getline(cin, sv.hoTen); // Nhập họ tên
    getline(cin, sv.lop);   // Nhập lớp
    getline(cin, sv.email); // Nhập email
    danhSachSV.push_back(sv);
  }

  // Sắp xếp danh sách sinh viên theo mã sinh viên
  sort(danhSachSV.begin(), danhSachSV.end(), compareByMaSV);

  // In danh sách sinh viên đã sắp xếp
  for (const SinhVien &sv : danhSachSV)
  {
    cout << sv.maSV << " " << sv.hoTen << " " << sv.lop << " " << sv.email << endl;
  }

  return 0;
}