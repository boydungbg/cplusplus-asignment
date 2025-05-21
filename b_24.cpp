#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // Mở tệp PTIT.in để đọc
  ifstream inputFile("PTIT.in");
  // Mở tệp PTIT.out để ghi
  ofstream outputFile("PTIT.out");

  // Kiểm tra nếu không mở được tệp đầu vào
  if (!inputFile)
  {
    cerr << "Khong the mo tep PTIT.in" << endl;
    return 1;
  }

  // Kiểm tra nếu không mở được tệp đầu ra
  if (!outputFile)
  {
    cerr << "Khong the mo tep PTIT.out" << endl;
    return 1;
  }

  // Đọc từng dòng từ tệp PTIT.in và ghi vào tệp PTIT.out
  string line;
  while (getline(inputFile, line))
  {
    outputFile << line << endl;
  }

  // Đóng cả hai tệp
  inputFile.close();
  outputFile.close();

  cout << "Da sao chep noi dung tu PTIT.in sang PTIT.out" << endl;
  return 0;
}