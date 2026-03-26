// Copyright 2026 cmg43 and jabak

#include<iostream>
using std::ostream;
#include"dyanimcarray.h"

class DynamicArray {

  friend ostream& DynamicArray::operator << (ostream& whereto, const DynamicArray object) {
		for ( int i = 0; i < object.size_; ++i ) {
			whereto << object[i] << delimiter_;
		}
		return whereto;
	}

 public:

  explicit DynamicArray::DynamicArray(int size = 1) size_ = 1 {
		if ( size > 0 ) {
			size_ = size;
		}
		values_ = new int[size_] {0};
	}

  explicit DynamicArray::DynamicArray(const DynamicArray other) {
		size_ = other.GetSize();
		values_ = new int[size_] {0};
		for ( int i = 0; i < size_; ++i ) {
			values_[i] = other[i];
		}
	}

	DynamicArray& operator = (const DynamicArray& other) {
		delete[] values_;
		size_ = other.GetSize();
		values_ = new int[size_] {0};
		for ( int i = 0; i < size_; ++i ) {
			values_[i] = other[i];
		}
		return *this;
	}


  static void DynamicArray::SetDelimiter(char delimiter) {
		delimiter_ = delimiter;
	}

  static char DynamicArray::GetDelimiter() {
		return delimiter_;
	}

  bool DynamicArray::operator == (DynamicArray&) const {
		
	}

  int DynamicArray::GetSize() const {
		return size_;	
	}

  void DynamicArray::SetSize(int size, bool copy = true) {
		
	}

  bool DynamicArray::AllUnique() const {
	
	}

  int DynamicArray::RemoveAll(int) {

	}

  int DynamicArray::FindAndReplace(int, int) {

	}

  void DynamicArray::RemoveDuplicates() {

	}

  void DynamicArray::Sort(bool desc = false) {

	}

  ~DynamicArray() {

	}    

 private:
  int size_;
  int * values_;
  static char delimiter_;
};
