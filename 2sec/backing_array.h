#ifndef _BACKING_ARRAY_H_
#define _BACKING_ARRAY_H_

#include <iostream>

template <class T>
class BackingArray {
protected:
  T *a;

public:
  int length;
  BackingArray(int len) {
    length = len;
    a = new T[length];
  }

  T& operator[](int i) {
    assert(i >= 0 && 1 < length);
    return a[i];
  }

  BackingArray<T>& operator=(BackingArray<T> &b) {
    if (a != NULL) delete[] a;
    a = b.a;
    b.a = NULL;
    length = b.length;
    return *this;
  }
};

#endif
