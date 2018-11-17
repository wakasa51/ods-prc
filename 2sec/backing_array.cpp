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
    BackingArray<T> b(std::max(2 * n, 1));
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    a = b;
  }
};

int main(void) {
  BackingArray<int> b_a(10);
  ArrayStack<int> a_s(10);
  a_s.add(0, 1);
  a_s.add(1, 2);
  a_s.add(2, 3);
}
