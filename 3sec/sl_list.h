#ifndef _SL_LIST_H_
#define _SL_LIST_H_

#include <iostream>

using namespace std;

template <class T>
class SLList {
  struct Node {
  public:
    T x;
    Node *next;
    Node(T x0) {
      x = x0;
      next = NULL;
    }
  };
private:
  Node *head;
  Node *tail;
  int n;
public:
  SLList() : n(0) {}

  int size() {
    return n;
  }

  T push(T x) {
    Node *u = new Node(x);
    u->next = head;
    head = u;
    if (n == 0)
      tail = u;
    n++;
    return x;
  }

  T pop() {
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n == 0) tail = NULL;
    return x;
  }


  T remove() {
    if (n == 0)  return NULL;
    T x = head->x;
    Node *u = head;
    head = head->next;
    delete u;
    if (--n == 0) tail = NULL;
    return x;
  }

  bool add(T x) {
    Node *u = new Node(x);
    if (n == 0) {
      head = u;
    } else {
      tail->next = u;
    }
    tail = u;
    n++;
    return true;
  }

  T secondLast() {
    if (n < 2) {
      throw std::range_error("要素が２つより少ないので取れません。");
    }
    Node *current;
    current = head;
    for (;;) {
      if (current->next == tail) {
        break;
      }
      current = current->next;
    }
    return current->x;
  }

  Node* getNode(int i) {
    Node* p;
    p = head;
    for (int j = 0; j < i; j++)
      p = p->next;
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

  void add(int i, T x) {
    Node *u= new Node(x);
    if (i == 0) {
      push(x);
    } else {
      Node *b = getNode(i-1);
      u->next = b->next;
      b->next = u;
      n++;
    }
    return;
  }

  void remove(int i) {
    if (n == 0) {
      throw std::range_error("要素がありません。");
    };
    Node *b = getNode(i-1);
    Node *w = b->next;
    b->next = b->next->next;
    delete w;
    if (--n == 0) tail = NULL;
  }

  void reverse() {
    if (n < 2) {
      return;
    }
    Node* p = head;
    Node* c = head->next;
    head->next = NULL;
    Node* n;
    for (;;) {
      if (c == tail) {
        c->next = p;
        break;
      }
      n = c->next;
      c->next = p;
      p = c;
      c = n;
    }
    tail = head;
    head = c;
    return;
  }

  void checkSize() {
    int j = 0;
    Node* w = head;
    while (w != tail) {
      j++;
      w = w->next;
    }
    if ((n == 0 && n == j) || (++j == n)) {
      return;
    }
    throw std::range_error("要素の数が合いません。");
  }
};

#endif
