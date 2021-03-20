#pragma once

#include <vector>
#include <cstdlib>
#include <cassert>

template <class T>
class Vector : public std::vector<T> {
    private:
        int begin_, end_;

    public:
        Vector(int = 0, int = 0);
        ~Vector();

        int begin(void) const;
        int end(void) const;

        void resize(int, int);

        T& operator[](int);
        T& operator[](int) const;
};

template <class T>
Vector<T>::Vector(int begin, int end) : begin_(begin), end_(end) {
    resize(begin_, end_);
}

template <class T>
Vector<T>::~Vector() {}

template <class T>
int Vector<T>::begin(void) const { return begin_; }

template <class T>
int Vector<T>::end(void) const { return end_; }

template <class T>
void Vector<T>::resize(int begin, int end) {
    assert((end - begin) >= 0);

    std::vector<T>::resize(end - begin);

    begin_ = begin;
    end_ = end;
}

template <class T>
T& Vector<T>::operator[](int pos) {
    assert((pos >= begin_) && (pos < end_));
    return ((std::vector<T>&)*this)[pos - begin_];
}

template <class T>
T& Vector<T>::operator[](int pos) const {
    assert((pos >= begin_) && (pos < end_));
    return ((std::vector<T>&)*this)[pos - begin_];
}