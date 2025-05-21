#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Khai báo cấu trúc Thí Sinh
struct ThiSinh {
    string hoTen;
    string ngaySinh;
    float diemMon1;
    float diemMon2;
    float diemMon3;
    float tongDiem;
};

int main() {
    ThiSinh ts;

    // Nhập thông tin thí sinh
    getline(cin, ts.hoTen);          // Nhập họ tên
    getline(cin, ts.ngaySinh);       // Nhập ngày sinh
    cin >> ts.diemMon1 >> ts.diemMon2 >> ts.diemMon3;

    // Tính tổng điểm
    ts.tongDiem = ts.diemMon1 + ts.diemMon2 + ts.diemMon3;

    // Xuất thông tin thí sinh
    cout << ts.hoTen << " " << ts.ngaySinh << " ";
    cout << fixed << setprecision(1) << ts.tongDiem << endl;

    return 0;
}