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

  void setSize(int i) {
    n = i;
  }

  int size() {
    return n;
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

  void checkSize() {
    int j = 0;
    Node *w = dummy.next;
    while (w != &dummy) {
      j++;
      w = w->next;
    }
    if (j == n) {
      return;
    }
    throw std::range_error("要素の数が合いません。");
  }

  Node* newaddBefore(Node *w, T x) {
    Node* n = new Node;
    n->x = x;
    n->next = w;
    n->prev = w->prev;
    w->prev->next = n;
    w->prev = n;
    return n;
  }

  bool isPalindrome() {
    Node* pv = dummy.prev;
    Node* nx = dummy.next;
    if (n % 2 == 1) {
      while (pv != nx) {
        if (pv->x != nx->x) {
          return false;
        }
        pv = pv->prev;
        nx = nx->next;
      }
    } else {
      while (pv != nx->next) {
        if (pv->x != nx->x) {
          return false;
        }
        pv = pv->prev;
        nx = nx->next;
      }
    }
    return true;
  }

  void rotate(int r) {
    dummy.prev->next = dummy.next;
    dummy.next->prev = dummy.prev;
    int counter;
    if (r < (n -r)) {
      counter = r;
      Node* pv = dummy.prev;
      while (counter--) {
        pv = pv->prev;
      }
      dummy.next = pv->next;
      dummy.prev = pv;
    } else {
      counter = n - r;
      Node* nx = dummy.next;
      while (counter--) {
        nx = nx->next;
      }
      dummy.next = nx;
      dummy.prev = nx->prev;
    }
  }

  DLList<T> truncate(int i) {
    Node* w = getNode(i);
    DLList<T> dl;
    dl.dummy.next = w;
    dl.dummy.prev = dummy.prev;
    dummy.prev = w->prev;
    dummy.prev->next = &dummy;
    dl.dummy.prev->next = &dl.dummy;
    dl.dummy.next->prev = &dl.dummy;
    dl.setSize(n - i);
    n = i;
    return dl;
  }

  void absorb(DLList<T> l2) {
    dummy.prev->next = l2.dummy.next;
    l2.dummy.next->prev = dummy.prev;
    dummy.prev = l2.dummy.prev;
    l2.dummy.prev->next = &dummy;
    setSize(n + l2.size());
    l2.dummy.next = &l2.dummy;
    l2.dummy.prev = &l2.dummy;
    l2.setSize(0);
  }

  DLList<T> deal() {
    DLList<T> dl;
    Node* w = dummy.next;
    Node* v = &dummy;
    Node* u = &dl.dummy;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 1) {
        w->prev = u;
        u->next = w;
        u = w;
      } else {
        w->prev = v;
        v->next = w;
        v = w;
      }
      w = w->next;
    }
    dl.dummy.prev = u;
    dummy.prev = v;
    int s = n / 2;
    dl.setSize(s);
    setSize(n - s);
    return dl;
  }

  void reverse() {
    Node* w = dummy.next;
    Node* u;
    dummy.next = dummy.prev;
    dummy.prev = w;
    for (int i = 0; i < n; i++) {
      u = w->next;
      w->next = w->prev;
      w->prev = u;
      w = u;
    }
  }

  void takeFirst(DLList<T> l2) {
    add(size(), l2.remove());
  }

  static DLList<T> merge(DLList<T> l1, DLList<T> l2) {
    DLList<T> l3;
    Node* w3 = &l3.dummy;
    Node* w1 = l1.dummy.next;
    Node* w2 = l2.dummy.next;
    Node* wd;
    int ts = l1.size() + l2.size();
    for (int i = 0; i < ts; i++) {
      if (w1->x < w2->x || w2 == &l2.dummy) {
        wd = w1;
        w1 = w1->next;
      } else {
        wd = w2;
        w2 = w2->next;
      }
      w3->next = wd;
      wd->prev = w3;
      w3 = wd;
    }
    l3.dummy.prev = wd;
    wd->next = &l3.dummy;
    l3.setSize(ts);
    l1.setSize(0);
    l2.setSize(0);
    return l3;
    /* 謎挙動がありバグっている… */
  }

  void sort() {
    if (size() < 2) {
      return;
    }
    DLList<T> l2 = truncate(size() / 2);
    /* わからない… */
  }
};

#endif
