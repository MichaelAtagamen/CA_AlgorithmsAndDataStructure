#pragma once
#ifndef MY_SET_H
#define MY_SET_H

#include "OrderedArray.h"

template <typename T>
class MySet : public OrderedArray<T> {
public:
    MySet(int growSize = 10);

    void insert(const T& element);

    MySet<T> operator|(const MySet<T>& other) const; // Union
    MySet<T> operator&(const MySet<T>& other) const; // Intersection
};

// Constructor (default growSize = 10)
template <typename T>
MySet<T>::MySet(int growSize)
    : OrderedArray<T>(growSize) {}

// Insert only if not already in set
template <typename T>
void MySet<T>::insert(const T& element) {
    if (this->search(element) == -1) {
        this->push(element);
    }
}

// Union of two sets
template <typename T>
MySet<T> MySet<T>::operator|(const MySet<T>& other) const {
    MySet<T> result;

    // Insert elements from first set
    for (int i = 0; i < this->length(); ++i) {
        result.insert(this->getElement(i));
    }

    // Insert elements from second set
    for (int i = 0; i < other.length(); ++i) {
        result.insert(other.getElement(i));
    }

    return result;
}

// Intersection of two sets
template <typename T>
MySet<T> MySet<T>::operator&(const MySet<T>& other) const {
    MySet<T> result;

    for (int i = 0; i < this->length(); ++i) {
        T element = this->getElement(i);
        if (other.search(element) != -1) {
            result.insert(element);
        }
    }

    return result;
}


#endif

