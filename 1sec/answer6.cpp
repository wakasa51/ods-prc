#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct OString {
  string line;
};
bool operator<(const OString &lhs, const OString &rhs){
  if (lhs.line.size() == rhs.line.size()) {
    return lhs.line < rhs.line;
  } else {
    return lhs.line.size() < rhs.line.size();
  }
}

int main(int argc, char** argv) {
  string filename = argv[1];

  ifstream reading_file;
  reading_file.open(filename, ios::in);

  cout << "reading " << filename << "..." << endl;

  string reading_line_buffer;

  set<OString> sset;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    OString str;
    str.line = reading_line_buffer;
    sset.insert(str);
  };

  int count = sset.size();

  auto itr = sset.begin();
  for (int i=0; i < count; i++) {
    OString str_line = *itr;
    cout << str_line.line << endl;
    itr++;
  }

  return 0;
}
