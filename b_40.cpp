#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Khai báo cấu trúc Người
struct Nguoi
{
  string ten;
  string ngaySinh;
};

// Hàm so sánh ngày sinh (già nhất đến trẻ nhất)
bool isOlder(const Nguoi &a, const Nguoi &b)
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

  vector<Nguoi> danhSach(N);

  // Nhập danh sách người
  for (int i = 0; i < N; i++)
  {
    cin >> danhSach[i].ten >> danhSach[i].ngaySinh;
  }

  // Tìm người trẻ nhất và người già nhất
  Nguoi treNhat = danhSach[0];
  Nguoi giaNhat = danhSach[0];

  for (int i = 1; i < N; i++)
  {
    if (isOlder(danhSach[i], giaNhat))
    {
      giaNhat = danhSach[i];
    }
    if (isOlder(treNhat, danhSach[i]))
    {
      treNhat = danhSach[i];
    }
  }

  // In kết quả
  cout << treNhat.ten << endl;
  cout << giaNhat.ten << endl;

  return 0;
}