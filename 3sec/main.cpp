#include <iostream>
#include "sl_list.h"
#include "dl_list.h"
#include "se_list.h"

using namespace std;

int main(void) {
  SLList<int> sl;
  sl.push(1);
  sl.push(2);
  sl.push(3);

  cout << sl.pop() << endl;
  cout << sl.pop() << endl;
  cout << sl.pop() << endl;
  sl.push(1);
  sl.push(2);
  sl.push(3);
  sl.reverse();
  sl.checkSize();
  cout << sl.pop() << endl;
  cout << sl.pop() << endl;
  cout << sl.pop() << endl;
}
