#ifndef _MIN_QUEUE_H_
#define _MIN_QUEUE_H_

#include <iostream>

using namespace std;

template <class T>

class MinQueue {
  struct Node {
    T x;
    Node *prev, *next;
    Node *min_prev, *min_next;
    Node(T x0) {
      x = x0;
      next = NULL;
      prev = NULL;
      min_next = NULL;
      min_prev = NULL;
    }
  };
  Node dummy;
  Node min_dummy;
  int n;

public:
  MinQueue() {
    dummy.next = &dummy;
    dummy.prev = &dummy;
    min_dummy.min_next = &min_dummy;
    min_dummy.min_prev = &min_dummy;
    n = 0;
  }

  int size() {
    return n;
  }

  T add(T x) {
    Node *u = new Node(x);
    if (n == 0) {
      dummy.next = u;
      dummy.prev = u;
      min_dummy.min_next = u;
      min_dummy.min_prev = u;
      return x;
    }
    u->prev = dummy.prev
    dummy.prev->next = u;
    dummy.prev = u;
    u->next = dummy;
    Node *w = min_dummy.min_prev;
    if (w->x >= x) {
      while (w == &min_dummy || w->x >= x) {
        min_remove();
        w = w->min_prev;
      }
      u->min_prev = min_dummy.min_prev
      min_dummy.min_prev->min_next = u;
      min_dummy.min_prev = u;
      u->min_next = min_dummy;
    }
    n++;
    return x;
  }

  T remove() {
    Node *w = dummy.next;
    w->next->prev = dummy;
    dummy->next = w->next;
    if (w->x == min_dummy.next->x) {
      w->min_next->min_prev = min_dummy;
      min_dummy->min_next = w->min_next;
    }
    delete w;
    n--;
  }

  /* 内部的に呼び出し用の関数のため、n--しない。 */
  void min_pop() {
    Node *w = min_dummy.min_prev;
    min_dummy.min_prev = min_dummy.min_prev->min_prev;
    min_dummy.min_prev->min_next = min_dummy;
  }

  T min() {
    return min_dummy.next->x;
  }
};

#endif
