#ifndef _DL_LIST_H_
#define _DL_LIST_H_

#include <iostream>

using namespace std;

template <class T>

class DLList {
  struct Node {
    T x;
    Node *prev, *next;
  };
  Node dummy;
  int n;

public:
  DLList() {
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
  }

  Node* getNode(int i) {
    Node* p;
    if (i < n / 2) {
      p = dummy.next;
      for (int j = 0; j < i; j++)
        p = p->next;
    } else {
      p = &dummy;
      for (int j = n; j > i; j--)
        p = p->prev;
    }
    return (p);
  }

  T get(int i) {
    return getNode(i)->x;
  }

  T set(int i, T x) {
    Node* u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
  }

  Node* addBefore(Node *w, T x) {
    Node *u = new Node;
    u->x = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    n++;
    return u;
  }

  void add(int i, T x) {
    addBefore(getNode(i), x);
  }

  void remove(Node *w) {
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    n--;
  }

  T remove(int i) {
    Node *w = getNode(i);
    T x = w->x;
    remove(w);
    return x;
  }
};

#endif
