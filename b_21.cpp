#include <iostream>
#include <string>
using namespace std;

// Khai báo cấu trúc Nhân Viên
struct NhanVien {
    string maNhanVien = "00001"; // Mã nhân viên mặc định
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string diaChi;
    string maSoThue;
    string ngayKyHopDong;
};

int main() {
    NhanVien nv;

    // Nhập thông tin nhân viên
    getline(cin, nv.hoTen);           // Nhập họ tên
    getline(cin, nv.gioiTinh);        // Nhập giới tính
    getline(cin, nv.ngaySinh);        // Nhập ngày sinh
    getline(cin, nv.diaChi);          // Nhập địa chỉ
    getline(cin, nv.maSoThue);        // Nhập mã số thuế
    getline(cin, nv.ngayKyHopDong);   // Nhập ngày ký hợp đồng

    // Xuất thông tin nhân viên
    cout << nv.maNhanVien << " " << nv.hoTen << " " << nv.gioiTinh << " "
         << nv.ngaySinh << " " << nv.diaChi << " " << nv.maSoThue << " "
         << nv.ngayKyHopDong << endl;

    return 0;
}