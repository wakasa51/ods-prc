#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

#include <iostream>
#include "backing_array.h"

using namespace std;

template <class T>
class ArrayQueue {
private:
  BackingArray<T> a;
  int j;
  int n;
public:
  ArrayQueue(int length) : j(0), n(0), a(length) {
  }

  bool add(T x) {
    if (n + 1 >= a.length) resize();
    a[(j+n) % a.length] = x;
    n++;
    return true;
  }

  T remove() {
    T x = a[j];
    j = (j + 1) % a.length;
    n--;
    if (a.length >= 3+n) resize();
    return x;
  }

  void resize() {
    BackingArray<T> b(max(2*n, 1));
    for (int k = 0; k < n; k++)
      b[k] = a[(j+k)%a.length];
    a = b;
    j = 0;
  }
};

#endif
