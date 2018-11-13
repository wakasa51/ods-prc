#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void prob1(ifstream &reading_file);

int main(int argc, char** argv) {
  string filename = argv[1];

  ifstream reading_file;
  reading_file.open(filename, ios::in);

  cout << "reading " << filename << "..." << endl;
  prob1(reading_file);

  return 0;
}

void prob1(ifstream &reading_file) {
  string reading_line_buffer;
  deque<string> dq1;
  deque<string> dq2;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    dq1.push_back(reading_line_buffer);
  }

  int dq1_size;
  dq1_size = dq1.size();
  for (int i=0; i < dq1_size; i++) {
    if (i % 2 == 0) {
      cout << dq1.front() << endl;
    } else {
      dq2.push_back(dq1.front());
    }
    dq1.pop_front();
  }

  int dq2_size;
  dq2_size = dq2.size();
  for (int i=0; i < dq2_size; i++) {
    cout << dq2.front() << endl;
    dq2.pop_front();
  }
}
