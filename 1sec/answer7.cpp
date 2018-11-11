#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct OString {
  string line;
  int d_count = 0;
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

  multiset<OString> mset;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    OString str;
    str.line = reading_line_buffer;
    mset.insert(str);
  };

  int s_size = mset.size();

  int d_counter = 1;
  auto itr = mset.begin();
  for (int i=0; i < s_size; i++) {
    OString this_str = *itr;
    itr++;
    OString next_str = *itr;
    if (this_str.line == next_str.line) {
      d_counter++;
    } else if (d_counter > 1) {
      cout << d_counter << endl;
      d_counter = 1;
    } else {
      cout << this_str.line << endl;
    }
  }

  return 0;
}
