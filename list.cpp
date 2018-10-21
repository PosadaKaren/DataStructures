#include <iostream>

using namespace std;

template <typename T>
class List {
private:
  class Nodo {
  private:
    T data;
    Nodo* next;
  public:
    Nodo(T d) {
      data = d;
      next =NULL ;
    }
    T getData() { return data; }
    void setNext(Nodo* n) {
      next = n;
    }
    Nodo* getNext() { return next; }
  };

  Nodo* first;
  Nodo* last;
  size_t sz;

public:
  List() {
    first = NULL;
    last = NULL;
    sz = 0;
  }

  size_t size() {
    return sz;
  }

  bool empty() {
    return first == NULL;
  }

  void push_back(T e) {
    Nodo* n = new Nodo(e); //1
    if (empty()) //2
      first = n;
    else
      last->setNext(n);
    last = n;
    sz++;
  }

  void printList() {
    Nodo* t = first;
    cout << "[";
    while(t != NULL) {
      cout << " " << t->getData();
      t = t->getNext();
    }
    cout << "]" << endl;
  }



};


