// Copyright 2026 cmg43 and jabak

#include<iostream>
using std::ostream;
#include"dyanimcarray.h"

class DynamicArray {

  friend ostream& operator << (ostream&, DynamicArray) {
		
	}

 public:

  explicit DynamicArray(int size = 1) size_ = 1 {
		if ( size > 0 ) {
			size_ = size;
		}
		values_ = new int[size_] {0};
	}

  explicit DynamicArray(const DynamicArray&) {
		
	}

  static void SetDelimiter(char) {

	}

  static char GetDelimiter() {
		
	}

  bool operator == (DynamicArray&) const {
		
	}

  int GetSize() const {
		
	}

  void SetSize(int, bool copy = true) {

	}

  bool AllUnique() const {
	
	}

  int RemoveAll(int) {

	}

  int FindAndReplace(int, int) {

	}

  void RemoveDuplicates() {

	}

  void Sort(bool desc = false) {

	}

  ~DynamicArray() {

	}    

 private:
  int size_;
  int * values_;
  static char delimiter_;
};
