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

// Hàm so sánh để sắp xếp theo lớp tăng dần, nếu cùng lớp thì sắp xếp theo mã sinh viên
bool compareByLopAndMaSV(const SinhVien &a, const SinhVien &b)
{
  if (a.lop == b.lop)
  {
    return a.maSV < b.maSV; // Nếu cùng lớp, sắp xếp theo mã sinh viên
  }
  return a.lop < b.lop; // Sắp xếp theo lớp
}

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<SinhVien> danhSachSV(N);

  // Nhập danh sách sinh viên
  for (int i = 0; i < N; i++)
  {
    getline(cin, danhSachSV[i].maSV);  // Nhập mã sinh viên
    getline(cin, danhSachSV[i].hoTen); // Nhập họ tên
    getline(cin, danhSachSV[i].lop);   // Nhập lớp
    getline(cin, danhSachSV[i].email); // Nhập email
  }

  // Sắp xếp danh sách sinh viên theo lớp và mã sinh viên
  sort(danhSachSV.begin(), danhSachSV.end(), compareByLopAndMaSV);

  // In danh sách sinh viên đã sắp xếp
  for (const SinhVien &sv : danhSachSV)
  {
    cout << sv.maSV << " " << sv.hoTen << " " << sv.lop << " " << sv.email << endl;
  }

  return 0;
}