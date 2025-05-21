#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

// Hàm đọc từ file và lưu các từ vào một tập hợp (set)
set<string> readWordsFromFile(const string &filename)
{
  ifstream file(filename);
  set<string> words;
  string line;

  if (!file)
  {
    cerr << "Không thể mở file " << filename << endl;
    return words;
  }

  while (getline(file, line))
  {
    stringstream ss(line);
    string word;

    // Đọc từng từ trong dòng
    while (ss >> word)
    {
      // Chuyển từ về dạng chữ thường
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      words.insert(word); // Thêm từ vào set
    }
  }

  file.close();
  return words;
}

int main()
{
  // Đọc từ từ hai file
  set<string> words1 = readWordsFromFile("DATA1.in");
  set<string> words2 = readWordsFromFile("DATA2.in");

  // Tính hợp của hai tập từ
  set<string> unionWords;
  set_union(words1.begin(), words1.end(), words2.begin(), words2.end(),
            inserter(unionWords, unionWords.begin()));

  // Tính giao của hai tập từ
  set<string> intersectionWords;
  set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
                   inserter(intersectionWords, intersectionWords.begin()));

  // In tập hợp
  for (const string &word : unionWords)
  {
    cout << word << " ";
  }
  cout << endl;

  // In giao
  for (const string &word : intersectionWords)
  {
    cout << word << " ";
  }
  cout << endl;

  return 0;
}