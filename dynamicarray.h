// Copyright 2026 started by bhipp, finished by cmg43 and jabak

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include<iostream>
using std::ostream;

class DynamicArray {
  friend ostream& operator << (ostream&, const DynamicArray&);

 public:
  explicit DynamicArray(int size = 1);

  explicit DynamicArray(const DynamicArray&);

  DynamicArray& operator = (const DynamicArray&);

  static void SetDelimiter(char);

  static char GetDelimiter();

  bool operator == (const DynamicArray&) const;

  int GetSize() const;

  void SetSize(int, bool copy = true);

  bool AllUnique() const;

  int RemoveAll(int);

  int FindAndReplace(int, int);

  void RemoveDuplicates();

  void Sort(bool desc = false);

	// Extra features
	void operator + (int);

	void operator * (int);

  ~DynamicArray();

  // version that allows one to use the operator in a non-constant setting
  // to update the values in the array
  int& operator[](int i) {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }

  // version that allows one to use the operator on a constant array
  // returning copies of a value in the array
  int operator[](int i) const {
    if ( i >= 0 && i < size_ ) return values_[i];
    if ( i < 0 ) return values_[0];
    return values_[size_ - 1];
  }


 private:
  int size_;
  int * values_;
  static char delimiter_;  // (for separator used by <<)
};

bool contains(int*, int, int);

#endif  // DYNAMICARRAY_H_
