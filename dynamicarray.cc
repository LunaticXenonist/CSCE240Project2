// Copyright 2026 cmg43 and jabak

#include<iostream>
using std::ostream;
#include"dynamicarray.h"

char DynamicArray::delimiter_ = ' ';  // default to space

  ostream& operator << (ostream& whereto, const DynamicArray& object) {
    for ( int i = 0; i < object.size_; ++i ) {
      whereto << object[i] << object.delimiter_;
    }
    return whereto;
  }


  DynamicArray::DynamicArray(int size): size_(1) {
    if ( size > 0 ) {
      size_ = size;
    }
    values_ = new int[size_]();
  }

  DynamicArray::DynamicArray(const DynamicArray& other) {
    size_ = other.GetSize();
    values_ = new int[size_];
    for ( int i = 0; i < size_; ++i ) {
      values_[i] = other[i];
    }
  }

  DynamicArray& DynamicArray::operator = (const DynamicArray& other) {
    delete[] values_;
    size_ = other.GetSize();
    values_ = new int[size_]();
    for ( int i = 0; i < size_; ++i ) {
      values_[i] = other[i];
    }
    return *this;
  }


  void DynamicArray::SetDelimiter(char delimiter) {
    delimiter_ = delimiter;
  }

  char DynamicArray::GetDelimiter() {
    return delimiter_;
  }

  bool DynamicArray::operator == (const DynamicArray& other) const {
    if ( size_ != other.GetSize() ) {
      return false;
    }
    for ( int i = 0; i < size_; ++i ) {
      if ( values_[i] != other[i] ) {
        return false;
      }
    }
    return true;
  }

  int DynamicArray::GetSize() const {
    return size_;
  }

  void DynamicArray::SetSize(int size, bool copy) {
    int * temp = values_;
    if (size <= 0) {
      values_ = new int[1]();
      delete temp;
      return;
    }
    values_ = new int[size]();
    if (copy) {
      int smallSize = size < size_ ? size : size_;
      for (int i = 0; i < smallSize; ++i) {
        values_[i] = temp[i];
      }
    }
    size_ = size;
    delete [] temp;
  }

  bool DynamicArray::AllUnique() const {
    int count = 0;
    for (int i = 0; i < size_; ++i) {
      for (int j = 0; j < size_; ++j) {
        if (values_[i] == values_[j]) {
          ++count;
          if (count >= 2)
            return false;
        }
      }
      count = 0;
    }
    return true;
  }

  int DynamicArray::RemoveAll(int target) {
    int count = 0;
    for (int i = 0; i < size_; ++i) {
      if (values_[i] == target) {
        ++count;
        for (int j = i; j < size_ - 1; ++j)
          values_[j] = values_[j + 1];
        --i;
        SetSize(size_ - 1);
      }
    }
    return count;  // checking for 0 size arrays is done in SetSize
  }

  int DynamicArray::FindAndReplace(int target, int replace) {
    int count = 0;
    for (int i = 0; i < size_; ++i) {
      if (values_[i] == target) {
        values_[i] = replace;
        ++count;
      }
    }
    return count;
  }

// small helper function
bool contains(int * ptr, int size, int item) {
  for (int i = 0; i < size; ++i) {
    if (item == ptr[i])
      return true;
  }
  return false;
}

  void DynamicArray::RemoveDuplicates() {
    int * unique = new int[size_] {values_[0]};
    // initialize the first value of the unique to values_[0] and the rest to 0
    int uniqueSize = 1;
    for (int i = 1; i < size_; ++i) {
      if (contains(unique, uniqueSize, values_[i])) {
        for (int j = i; j < size_ - 1; ++j)
          values_[j] = values_[j + 1];
        --i;
        SetSize(size_ - 1);
      } else {
        unique[uniqueSize] = values_[i];
        ++uniqueSize;
      }
    }
    delete[] unique;  // fix leak
  }

  void DynamicArray::Sort(bool desc) {
    int temp;
    for (int i = 0; i < size_; ++i) {
      for (int j = 0; j < (size_ - i - 1); ++j) {
        if ((desc ? (values_[j] < values_[j + 1]) :
        (values_[j] > values_[j + 1]))) {
          temp = values_[j + 1];
          values_[j + 1] = values_[j];
          values_[j] = temp;
        }
      }
    }
  }

// Extra features
void DynamicArray::operator + (int scalar) {
  for ( int i = 0; i < size_; ++i ) {
    values_[i] += scalar;
  }
}

void DynamicArray::operator * (int scalar) {
  for ( int i = 0; i < size_; ++i ) {
    values_[i] *= scalar;
  }
}

DynamicArray::~DynamicArray() {
    delete[] values_;
}
