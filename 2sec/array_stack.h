#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

#include <iostream>
#include "backing_array.h"

using namespace std;

template <class T>
class ArrayStack {
private:
  BackingArray<T> a;
  int n;
public:
  ArrayStack(int length) : n(0), a(length) {
  }

  int size() {
    return n;
  }

  T get(int i) {
    return a[i];
  }

  T set(int i, T x) {
    T y = a[i];
    a[i] = x;
    return y;
  }

  void add(int i, T x) {
    if (n + 1 >= a.length) resize();
    for (int j = n; j > i; j--)
      a[j] = a[j - i];
    a[i] = x;
    n++;
  }

  T remove(int i) {
    T x = a[i];
    for (int j = i; j < n - 1; j++)
      a[j] = a[j + 1];
    n--;
    if (a.length >= 3 * n) resize();
    return x;
  }

  void resize() {
    BackingArray<T> b(max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    a = b;
  }
};

#endif
