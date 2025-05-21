#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Khai báo cấu trúc Doanh Nghiệp
struct DoanhNghiep
{
  string maDN;
  string tenDN;
  int soSV;
};

// Hàm so sánh để sắp xếp theo số lượng sinh viên giảm dần, nếu bằng nhau thì theo mã doanh nghiệp tăng dần
bool compare(const DoanhNghiep &a, const DoanhNghiep &b)
{
  if (a.soSV == b.soSV)
  {
    return a.maDN < b.maDN; // Nếu số lượng sinh viên bằng nhau, sắp xếp theo mã doanh nghiệp
  }
  return a.soSV > b.soSV; // Sắp xếp theo số lượng sinh viên giảm dần
}

int main()
{
  int N;
  cin >> N;
  cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập N

  vector<DoanhNghiep> danhSachDN(N);

  // Nhập danh sách doanh nghiệp
  for (int i = 0; i < N; i++)
  {
    getline(cin, danhSachDN[i].maDN);  // Nhập mã doanh nghiệp
    getline(cin, danhSachDN[i].tenDN); // Nhập tên doanh nghiệp
    cin >> danhSachDN[i].soSV;         // Nhập số sinh viên có thể nhận
    cin.ignore();                      // Bỏ qua ký tự xuống dòng
  }

  // Sắp xếp danh sách doanh nghiệp
  sort(danhSachDN.begin(), danhSachDN.end(), compare);

  // In danh sách doanh nghiệp đã sắp xếp
  for (const DoanhNghiep &dn : danhSachDN)
  {
    cout << dn.maDN << " " << dn.tenDN << " " << dn.soSV << endl;
  }

  return 0;
}