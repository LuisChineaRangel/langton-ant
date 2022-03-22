/// @file SmartVector.hpp
/// @brief Smart Vector Class Header
#pragma once

#include <cassert>
#include <cstdlib>
#include <exception>
#include <vector>

#include <iostream>

/// @class WrongIndex
/// @brief Exception to detect problematics indexes
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// size_t pos == -1;
/// size_t (pos == -1) throw WrongIndex();
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class WrongIndex : public std::exception {
public:
  virtual const char *what(void) const throw();
};

/// @brief What Method
/// @return Exception Message
inline const char *WrongIndex::what(void) const throw() {
  return "Wrong index. Trying to access to an illegal memory location";
}

/// @class SmartVector
/// @brief Negative and Positive indexes Vector
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// SmartVector<int> v(-5, 5);
/// v[-1] = 5;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <class T> class SmartVector : public std::vector<T> {
private:
  size_t begin_, end_;

public:
  /** @name Constructors and Destructor */
  /// @{
  SmartVector(size_t = 0, size_t = 0);
  ~SmartVector();
  /// @}

  /** @name Auxiliar Public Methods */
  /// @{
  size_t Begin(void) const;
  size_t Center(void) const;
  size_t End(void) const;
  void Resize(size_t, size_t);
  /// @}

  /** @name Operators Overloading */
  /// @{
  T &operator[](size_t);
  T &operator[](size_t) const;
  /// @}
};

/// @brief Default Constructor. Initializes ant behavior and attributes
template <class T>
SmartVector<T>::SmartVector(size_t begin, size_t end)
    : begin_(begin), end_(end) {
  Resize(begin_, end_);
}

/// @brief Destructor
template <class T> SmartVector<T>::~SmartVector() {}

/// @brief Begin Method
/// @return Smart Vector's Beginning
template <class T> size_t SmartVector<T>::Begin(void) const { return begin_; }

/// @brief Center Method
/// @return Smart Vector's Center
template <class T> size_t SmartVector<T>::Center(void) const {
  return end_ - (std::vector<T>::size() / 2);
}

/// @brief End Method
/// @return Smart Vector's Ending
template <class T> size_t SmartVector<T>::End(void) const { return end_; }

/// @brief Resize Method. Reduces the or Increases in both directions the Smart
/// Vector size
/// @return Void
template <class T> void SmartVector<T>::Resize(size_t begin, size_t end) {
  assert((end - begin) >= 0);
  std::vector<T>::resize(end - begin);
  begin_ = begin;
  end_ = end;
}

/// @brief [] Operator Overloading
/// @return Value located in the index
template <class T> T &SmartVector<T>::operator[](size_t pos) {
  if ((pos < begin_) || (pos >= end_))
    throw WrongIndex();
  return ((std::vector<T> &)*this)[long(pos) - begin_];
}

/// @brief [] Operator Overloading. Constant version
/// @return Value located in the index
template <class T> T &SmartVector<T>::operator[](size_t pos) const {
  if ((pos < begin_) || (pos >= end_))
    throw WrongIndex();
  return ((std::vector<T> &)*this)[pos - begin_];
}