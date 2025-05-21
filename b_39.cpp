#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// Khai báo cấu trúc Sinh Viên
struct SinhVien
{
  string maSV;
  string hoTen;
  string lop;
  float diem1, diem2, diem3;
};

// Hàm so sánh để sắp xếp theo họ tên (thứ tự từ điển tăng dần)
bool compareByHoTen(const SinhVien &a, const SinhVien &b)
{
  return a.hoTen < b.hoTen;
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
    getline(cin, sv.maSV);                   // Nhập mã sinh viên
    getline(cin, sv.hoTen);                  // Nhập họ tên
    getline(cin, sv.lop);                    // Nhập lớp
    cin >> sv.diem1 >> sv.diem2 >> sv.diem3; // Nhập điểm 1, điểm 2, điểm 3
    cin.ignore();                            // Bỏ qua ký tự xuống dòng

    danhSachSV[i] = sv;
  }

  // Sắp xếp danh sách sinh viên theo họ tên
  sort(danhSachSV.begin(), danhSachSV.end(), compareByHoTen);

  // In danh sách sinh viên
  for (int i = 0; i < N; i++)
  {
    const SinhVien &sv = danhSachSV[i];
    cout << i + 1 << " " << sv.maSV << " " << sv.hoTen << " " << sv.lop << " "
         << fixed << setprecision(1) << sv.diem1 << " "
         << fixed << setprecision(1) << sv.diem2 << " "
         << fixed << setprecision(1) << sv.diem3 << endl;
  }

  return 0;
}