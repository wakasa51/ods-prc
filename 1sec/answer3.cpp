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
    if (dq.size() == 42) {
      string express_line;
      if (reading_line_buffer == "\0") {
        express_line = dq.front();
      } else {
        express_line = reading_line_buffer;
      }
      cout << express_line << endl;
      dq.pop_front();
    } else {
      cout << reading_line_buffer << endl;
    }
    dq.push_back(reading_line_buffer);
  }

  return 0;
}
