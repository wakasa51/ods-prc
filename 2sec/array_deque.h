#ifndef _ARRAY_DEQUE_H_
#define _ARRAY_DEQUE_H_

#include <iostream>
#include "backing_array.h"

using namespace std;

template <class T>
class ArrayDeque {
private:
  BackingArray<T> a;
  int j;
  int n;
public:
  ArrayQueue(int length) : j(0), n(0), a(length) {
  }

  T get(int i) {
    return a[(j + i) % a.length];
  }

  T set(int i, T x) {
    T y = a[(j + i) % a.length];
    a[(j + i) % a.length] = x;
    return y;
  }

  void add(int i, T x) {
    if (n + 1 >= a.length) resize();
    if (i < n/2) {
      j = (j == 0) ? a.length - 1 : j - 1;
      for (int k = 0; k <= i - 1; k++)
        a[(j+k)%a.length] = a[(j+k+1)%a.length];
    } else {
      for (int k = n; k > i; k--)
        a[(j+k)%a.length] = a[(j+k-1)%a.length];
    }
    a[(j+i) % a.length] = x;
    n++;
  }

  T remove(int i) {
    T x = a[(j+i)%a.length];
    if (i < n/2) {
      for (int k = i; k > 0; k--)
        a[(j+k)%a.length] = a[(j+k-1)%a.length];
      j = (j + 1) % a.length;
    } else {
      for (int k = i; k < n-1; k++)
        a[(j+k)%a.length] = a[(j+k+1)%a.length];
    }
    n--;
    if (a.length > 3*n) resize();
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
