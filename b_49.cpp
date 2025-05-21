#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
  ifstream file("VANBAN.in"); // Mở file VANBAN.in
  if (!file)
  {
    cerr << "Không thể mở file VANBAN.in" << endl;
    return 1;
  }

  set<string> uniqueWords; // Sử dụng set để lưu các từ khác nhau (tự động sắp xếp theo thứ tự từ điển)
  string line;

  // Đọc từng dòng trong file
  while (getline(file, line))
  {
    stringstream ss(line);
    string word;

    // Đọc từng từ trong dòng
    while (ss >> word)
    {
      // Chuyển từ về dạng chữ thường
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      uniqueWords.insert(word); // Thêm từ vào set
    }
  }

  file.close(); // Đóng file

  // In các từ khác nhau theo thứ tự từ điển
  for (const string &word : uniqueWords)
  {
    cout << word << endl;
  }

  return 0;
}