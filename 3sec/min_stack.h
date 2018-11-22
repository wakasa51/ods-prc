#ifndef _MIN_STACK_H_
#define _MIN_STACK_H_

#include <iostream>

using namespace std;

template <class T>

class MinStack {
  struct Node {
    T x;
    Node *next;
    Node *min_next;
    Node(T x0) {
      x = x0;
      next = NULL;
      min_next = NULL;
    }
  };
  Node *head;
  Node *min_head;
  int n;

public:
  MinStack() : n(0) {
  }

  int size() {
    return n;
  }

  T push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (n == 0) {
      min_head = u;
    } else if (head->x >= x) {
      u->min_next = min_head;
      min_head = u;
    }
    n++;
    return x;
  }

  T pop() {
    T x = head->x;
    Node *u = head;
    head = head->next;
    if (min_head->x == x) {
      min_head = min_head->next;
    }
    delete u;
    if (--n == 0) min_head = NULL;
    return x;
  }

  T min() {
    return min_head->x;
  }
};

#endif
