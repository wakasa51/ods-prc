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

  DLList<int> dl;
  dl.add(0, 1);
  /* dl.add(1, 3); */
  /* dl.add(2, 4); */
  DLList<int> tdl;
  tdl.add(0, 2);
  tdl.add(1, 5);
  /* dl.add(5, 6); */
  DLList<int> mdl = DLList<int>::merge(dl, tdl);
  cout << mdl.get(0) << endl;
  cout << mdl.getNode(0)->next->x << endl;
  cout << mdl.getNode(0)->next->next->x << endl;
  cout << mdl.get(0) << endl;
  cout << mdl.get(1) << endl;
  cout << mdl.get(2) << endl;
  /* cout << mdl.get(3) << endl; */
  /* cout << mdl.get(4) << endl; */
  /* cout << mdl.get(5) << endl; */
  /* cout << tdl.get(0) << endl; */
  /* cout << tdl.get(1) << endl; */
  /* cout << tdl.get(2) << endl; */

  SEList<int> se(3);
  se.add(1);
  se.add(2);
  se.add(1);
  se.get(0);
}
