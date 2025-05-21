#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;

// Khai báo cấu trúc Sinh Viên
struct SinhVien
{
  string maSV;
  string hoTen;
  string lop;
  string ngaySinh;
  float gpa;
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

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<SinhVien> danhSachSV(N);

  for (int i = 0; i < N; i++)
  {
    SinhVien sv;
    getline(cin, sv.hoTen);    // Nhập họ tên
    getline(cin, sv.lop);      // Nhập lớp
    getline(cin, sv.ngaySinh); // Nhập ngày sinh
    cin >> sv.gpa;             // Nhập GPA
    cin.ignore();              // Bỏ qua ký tự xuống dòng

    // Tạo mã sinh viên
    stringstream ss;
    ss << "B20DCCN" << setw(3) << setfill('0') << (i + 1);
    sv.maSV = ss.str();

    // Chuẩn hóa ngày sinh
    sv.ngaySinh = chuanHoaNgaySinh(sv.ngaySinh);

    danhSachSV[i] = sv;
  }

  // In danh sách sinh viên
  for (const SinhVien &sv : danhSachSV)
  {
    cout << sv.maSV << " " << sv.hoTen << " " << sv.lop << " "
         << sv.ngaySinh << " " << fixed << setprecision(2) << sv.gpa << endl;
  }

  return 0;
}