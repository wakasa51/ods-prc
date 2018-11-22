#ifndef _SE_LIST_H_
#define _SE_LIST_H_

#include <iostream>
#include "../2sec/array_deque.h"

using namespace std;

template <class T>
class SEList {
  class BDeque : public ArrayDeque<T> {
  public:
    BDeque(int b) : ArrayDeque<T>(b+1) { }

    ~BDeque() { }
    void add(int i, T x) {
      ArrayDeque<T>::add(i, x);
    }
    bool add(T x) {
      add(ArrayDeque<T>::size(), x);
      return true;
    }
    void resize() {}
  };

  struct Node {
  public:
    BDeque d;
    Node *prev, *next;
    Node(int b) : d(b) { }
  };

  struct Location {
  public:
    Node *u;
    int j;
    Location() { }
    Location(Node *u, int j) {
      this->u = u;
      this->j = j;
    }
  };

  int n;
  int b;
  Node dummy;

public:
  SEList(int b) : n(0), b(b), dummy(0) {
    dummy.prev = &dummy;
    dummy.next = &dummy;
  }

  int size() {
    return n;
  }

  void getLocation(int i, Location &ell) {
    if (i < n / 2) {
      Node *u = dummy.next;
      while (i >= u->d.size()) {
        i -= u->d.size();
        u = u->next; }
      ell.u = u;
      ell.j = i;
    } else {
      Node *u = &dummy;
      int idx = n;
      while (i < idx) {
        u = u->prev;
        idx -= u->d.size();
      }
      ell.u = u;
      ell.j = i - idx;
    }
  }

  T get(int i) {
    Location l;
    getLocation(i, l);
    return l.u->d.get(l.j);
  }

  T set(int i, T x) {
    Location l;
    getLocation(i, l);
    T y = l.u->d.get(l.j);
    l.u->d.set(l.j, x);
    return y;
  }

  void add(T x) {
    Node *last = dummy.prev;
    if (last == &dummy || last->d.size() == b+1) {
      last = addBefore(&dummy);
    }
    last->d.add(x);
    n++;
  }

  void add(int i, T x) {
    if (i == n) {
      add(x);
      return;
    }
    Location l;
    getLocation(i, l);
    Node *u = l.u;
    int r = 0;
    while (r < b && u != &dummy && u->d.size() == b+1) {
      u = u->next;
      r++; }
    if (r == b) { // b+1 要素を含むブロックが b 個あった
      spread(l.u);
      u = l.u;
    }
    if (u == &dummy) { // 末尾まで到達したので新たなノードを加える
      u = addBefore(u);
    }
    while (u != l.u) { // 逆方向に要素をシフトする
      u->d.add(0, u->prev->d.remove(u->prev->d.size()-1)); u = u->prev;
    }
    u->d.add(l.j, x);
    n++;
  }

  T remove(int i) {
    Location l; getLocation(i, l);
    T y = l.u->d.get(l.j);
    Node *u = l.u;
    int r = 0;
    while (r < b && u != &dummy && u->d.size() == b - 1) {
      u = u->next;
      r++; }
    if (r == b) { // b-1 要素を含むブロックが b 個あった
      gather(l.u);
    }
    u = l.u;
    u->d.remove(l.j);
    while (u->d.size() < b - 1 && u->next != &dummy) {
      u->d.add(u->next->d.remove(0));
      u = u->next; }
    if (u->d.size() == 0)
      remove(u);
    n--;
    return y;
  }

  void spread(Node *u) {
    Node *w = u;
    for (int j = 0; j < b; j++) {
      w = w->next;
    }
    w = addBefore(w);
    while (w != u) {
      while (w->d.size() < b)
        w->d.add(0, w->prev->d.remove(w->prev->d.size()-1));
      w = w->prev;
    }
  }

  void gather(Node *u) {
    Node *w = u;
    for (int j = 0; j < b-1; j++) {
      while (w->d.size() < b)
        w->d.add(w->next->d.remove(0));
      w = w->next;
    }
    remove(w);
  }

  Node* addBefore(Node *w) {
    Node *u = new Node(b);
    u->prev = w->prev;
    u->next = w;
    w->prev = u;
    u->prev->next = u;
    n++;
    return u;
  }
};

#endif
