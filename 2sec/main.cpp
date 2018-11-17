#include <iostream>
#include "backing_array.h"
#include "array_stack.h"
#include "array_queue.h"

using namespace std;

int main(void) {
  ArrayStack<int> a_s(2);
  ArrayQueue<int> a_q(2);
  a_s.add(0, 1);
  a_s.add(1, 2);
  a_s.add(2, 3);
  a_s.add(3, 4);
  a_q.add(0);
  a_q.add(1);
  a_q.add(2);
  a_q.add(3);

  cout << a_s.remove(3) << endl;
  cout << a_s.remove(2) << endl;
  cout << a_s.remove(1) << endl;
  cout << a_s.remove(0) << endl;
  cout << a_q.remove() << endl;
  cout << a_q.remove() << endl;
  cout << a_q.remove() << endl;
  cout << a_q.remove() << endl;
}
