#include <iostream>
#include <random>
#include <algorithm>
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
  random_device get_rand_dev;
  mt19937 get_rand_mt(get_rand_dev());
  deque<string> dq;

  while (!reading_file.eof())
  {
    getline(reading_file, reading_line_buffer);
    dq.push_back(reading_line_buffer);
  }

  int dq_size;
  dq_size = dq.size();
  shuffle(dq.begin(), dq.end(), get_rand_mt );
  for (int i=0; i < dq_size; i++) {
    cout << dq.front() << endl;
    dq.pop_front();
  }
}
