#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Khai báo cấu trúc Giảng Viên
struct GiangVien
{
  string maGV;
  string hoTen;
  string boMon;
};

// Hàm viết tắt bộ môn
string vietTatBoMon(const string &boMon)
{
  stringstream ss(boMon);
  string word, result = "";
  while (ss >> word)
  {
    result += toupper(word[0]); // Lấy chữ cái đầu và viết hoa
  }
  return result;
}

// Hàm kiểm tra từ khóa có xuất hiện trong tên giảng viên (không phân biệt chữ hoa chữ thường)
bool timKiemTen(const string &hoTen, const string &tuKhoa)
{
  string hoTenLower = hoTen, tuKhoaLower = tuKhoa;
  transform(hoTenLower.begin(), hoTenLower.end(), hoTenLower.begin(), ::tolower);
  transform(tuKhoaLower.begin(), tuKhoaLower.end(), tuKhoaLower.begin(), ::tolower);
  return hoTenLower.find(tuKhoaLower) != string::npos;
}

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<GiangVien> danhSachGV(N);

  // Nhập danh sách giảng viên
  for (int i = 0; i < N; i++)
  {
    getline(cin, danhSachGV[i].hoTen); // Nhập họ tên
    getline(cin, danhSachGV[i].boMon); // Nhập bộ môn

    // Tạo mã giảng viên
    stringstream ss;
    ss << "GV" << (i + 1 < 10 ? "0" : "") << (i + 1);
    danhSachGV[i].maGV = ss.str();

    // Viết tắt bộ môn
    danhSachGV[i].boMon = vietTatBoMon(danhSachGV[i].boMon);
  }

  int Q;
  cin >> Q;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập Q

  // Xử lý các truy vấn
  while (Q--)
  {
    string tuKhoa;
    getline(cin, tuKhoa); // Nhập từ khóa

    cout << "DANH SACH GIANG VIEN THEO TU KHOA " << tuKhoa << ":" << endl;
    for (const GiangVien &gv : danhSachGV)
    {
      if (timKiemTen(gv.hoTen, tuKhoa))
      {
        cout << gv.maGV << " " << gv.hoTen << " " << gv.boMon << endl;
      }
    }
  }

  return 0;
}