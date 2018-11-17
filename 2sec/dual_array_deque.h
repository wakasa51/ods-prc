#ifndef _DUAL_ARRAY_DEQUE_H_
#define _DUAL_ARRAY_DEQUE_H_

#include <iostream>
#include "array_stack.h"

using namespace std;

template <class T>
class DualArrayDeque {
private:
  ArrayStack<T> front;
  ArrayStack<T> back;
public:
  DualArrayDeque(int length) : front(length), back(length) {
  }

  T get(int i) {
    if (i < front.size()) {
      return front.get(front.size() - i - 1);
    } else {
      return back.get(i - front.size());
    }
  }

  T set(int i, T x) {
    if (i < front.size()) {
      return front.set(front.size() - i - 1, x);
    } else {
      return back.set(i - front.size(), x);
    }
  }

  void add(int i, T x) {
    if (i < front.size()) {
      front.add(front.size() - i, x);
    } else {
      back.add(i - front.size(), x);
    }
    balance();
  }

  T remove(int i) {
    T x;
    if (i < front.size()) {
      x = front.remove(front.size() - i - 1);
    } else {
      x = back.remove(i - front.size());
    }
    balance();
    return x;
  }

  void balance() {
    if (3*front.size() < back.size()
        || 3*back.size() < front.size()) {
      int n = front.size() + back.size();
      int nf = n/2;
      array<T> af(max(2*nf, 1));
      for (int i = 0; i < nf; i++) {
        af[nf-i-1] = get(i);
      }
      int nb = n - nf;
      array<T> ab(max(2*nb, 1));
      for (int i = 0; i < nb; i++) {
        ab[i] = get(nf+i);
      }
      front.a = af;
      front.n = nf;
      back.a = ab;
      back.n = nb;
    }
  }
};

#endif
