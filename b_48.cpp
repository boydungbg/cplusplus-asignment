#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
  ifstream file("DATA.in"); // Mở file DATA.in
  if (!file)
  {
    cerr << "Không thể mở file DATA.in" << endl;
    return 1;
  }

  map<int, int> frequency; // Map để lưu số và số lần xuất hiện
  int number;

  // Đọc các số từ file và đếm tần suất
  while (file >> number)
  {
    frequency[number]++;
  }

  file.close(); // Đóng file

  // In các số khác nhau và số lần xuất hiện theo thứ tự tăng dần
  for (const auto &entry : frequency)
  {
    cout << entry.first << " " << entry.second << endl;
  }

  return 0;
}