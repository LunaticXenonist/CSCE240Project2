// Copyright 2026 cmg43 and jabak

#include<iostream>
using std::ostream;
#include"dyanimcarray.h"


  ostream& DynamicArray::operator << (ostream& whereto, const DynamicArray object) {
    for ( int i = 0; i < object.size_; ++i ) {
			whereto << object[i] << delimiter_;
		}
		return whereto;
	}


  DynamicArray::DynamicArray(int size = 1) size_ = 1 {
		if ( size > 0 ) {
			size_ = size;
		}
		values_ = new int[size_]();
	}

  DynamicArray::DynamicArray(const DynamicArray other) {
		size_ = other.GetSize();
		values_ = new int[size_];
		for ( int i = 0; i < size_; ++i ) {
			values_[i] = other[i];
		}
	}

	DynamicArray& operator = (const DynamicArray& other) {
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

  void DynamicArray::SetSize(int size, bool copy = true) {
		int * temp = values_;
    if (size <= 0) {
      values = new int[1]();
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
    delete temp;
	}

  bool DynamicArray::AllUnique() const {
    int count = 0;
	  for (int i = 0; i < size_; ++i) {
      for (int j = 0; i < size_; ++j) {
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
      if (values[i] == target) {
        ++count;
        for (int j = i; j < size_ - 1; ++j)
          values[j] = values[j + 1];
        --i;
        SetSize(size_ - 1);
      }
    }
    return count; // checking for 0 size arrays is done in SetSize
	}

  int DynamicArray::FindAndReplace(int target, int new) {

	}

  void DynamicArray::RemoveDuplicates() {

	}

  void DynamicArray::Sort(bool desc = false) {

	}

  ~DynamicArray() {
		delete[] values_;
	}    

 private:
  int size_;
  int * values_;
  static char delimiter_;
};
