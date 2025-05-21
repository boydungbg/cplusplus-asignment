#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Khai báo cấu trúc Sinh Viên
struct SinhVien
{
  string maSV;
  string hoTen;
  string lop;
  string email;
};

// Hàm kiểm tra ngành học dựa trên mã sinh viên và lớp
bool thuocNganh(const SinhVien &sv, const string &nganh)
{
  string maNganh = sv.maSV.substr(3, 4); // Lấy 4 ký tự từ vị trí thứ 4 trong mã sinh viên
  if (nganh == "Ke toan" && maNganh == "DCKT")
  {
    return true;
  }
  if (nganh == "Cong nghe thong tin" && maNganh == "DCCN" && sv.lop[0] != 'E')
  {
    return true;
  }
  if (nganh == "An toan thong tin" && maNganh == "DCAT" && sv.lop[0] != 'E')
  {
    return true;
  }
  if (nganh == "Vien thong" && maNganh == "DCVT")
  {
    return true;
  }
  if (nganh == "Dien tu" && maNganh == "DCDT")
  {
    return true;
  }
  return false;
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

  int Q;
  cin >> Q;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập Q

  // Xử lý các truy vấn
  while (Q--)
  {
    string nganh;
    getline(cin, nganh); // Nhập tên ngành

    cout << "DANH SACH SINH VIEN NGANH " << nganh << ":" << endl;
    for (const SinhVien &sv : danhSachSV)
    {
      if (thuocNganh(sv, nganh))
      {
        cout << sv.maSV << " " << sv.hoTen << " " << sv.lop << " " << sv.email << endl;
      }
    }
  }

  return 0;
}