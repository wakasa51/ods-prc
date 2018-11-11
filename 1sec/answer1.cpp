#include <iostream>
#include <deque>
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
  deque<string> dq;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    dq.push_back(reading_line_buffer);
  }

  int size;
  size = dq.size();
  for (int i=0; i<size; i++) {
    cout << dq.back() << endl;
    dq.pop_back();
  }

  return 0;
}
