
#include <string>
#include <iostream>
using namespace std;
template <typename T>
class Vector {
private:
  T* storage_;
  size_t capacity_;
  size_t size_;

public:
 
  Vector() {
    capacity_ = 3;
    size_ = 0;
    storage_ = new T[capacity_];
  }

 
  ~Vector() { delete[] storage_; }

 
  Vector(const Vector<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    storage_ = new T[capacity_];
    for (int i = 0; i < other.size_; i++) storage_[i] = other.storage_[i];
  }

 
  size_t size() const { return size_; }


  void push_backv(T elem) {
    if (capacity_ == size_) resize();
    storage_[size_] = elem;
    size_++;
  }

private:
  
  void resize() {

    size_t newCapacity = capacity_*2;
    T* newStorage = new T[newCapacity];
    for (int i = 0; i < size_; i++) {
      newStorage[i] = storage_[i];
    }
    delete[] storage_;
    storage_ = newStorage;
    capacity_ = newCapacity;
  }

public:
 
  size_t waste(){
    return capacity_ - size_;
  }


  T& at(size_t pos) { return storage_[pos]; }

 
 
  T& operator[](size_t pos) { return at(pos); }
};


