#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
  string filename = argv[1];

  ifstream reading_file;
  reading_file.open(filename, ios::in);

  cout << "reading " << filename << "..." << endl;

  string reading_line_buffer;
  unordered_set<string> uset;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    auto p = uset.insert(reading_line_buffer);
    if (!p.second) {
      cout << reading_line_buffer << endl;
    }
  }

  return 0;
}
