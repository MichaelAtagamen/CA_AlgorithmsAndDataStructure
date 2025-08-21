#pragma once
#ifndef ORDERED_ARRAY_H
#define ORDERED_ARRAY_H

#include <iostream>

template <typename T>
class OrderedArray {
public:
    OrderedArray(int growSize);
    OrderedArray(); // default constructor
    ~OrderedArray();

    void push(const T& newElement);   // Insert element in order
    int length() const;               // Number of elements
    T getElement(int index) const;    // Access element at index
    bool remove(int index);           // Remove element at index
    int search(const T& target) const; // Binary search
    void clear();                     // Clear all elements

private:
    void resize();                    // Increase capacity

    T* data;
    int size;        // Actual number of elements stored
    int capacity;    // Total capacity of array
    int growSize;    // Amount to grow when resizing
};

// ================= Constructors & Destructor =================
template <typename T>
OrderedArray<T>::OrderedArray(int growSize)
    : data(nullptr), size(0), capacity(0), growSize(growSize) {
}

template <typename T>
OrderedArray<T>::OrderedArray() : OrderedArray(10) {} // default grow size = 10

template <typename T>
OrderedArray<T>::~OrderedArray() {
    delete[] data;
}

// ================= Private Resize Function =================
template <typename T>
void OrderedArray<T>::resize() {
    int newCapacity = capacity + growSize;
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// ================= Public Functions =================
template <typename T>
void OrderedArray<T>::push(const T& newElement) {
    if (size == capacity) {
        resize();
    }

    // Insert in sorted order
    int i = size - 1;
    while (i >= 0 && data[i] > newElement) {
        data[i + 1] = data[i];
        i--;
    }
    data[i + 1] = newElement;
    size++;
}

template <typename T>
int OrderedArray<T>::length() const {
    return size;
}

template <typename T>
T OrderedArray<T>::getElement(int index) const {
    if (index < 0 || index >= size) {
        return T(); // Return default-constructed T if out of bounds
    }
    return data[index];
}

template <typename T>
bool OrderedArray<T>::remove(int index) {
    if (index < 0 || index >= size) return false;
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return true;
}

template <typename T>
int OrderedArray<T>::search(const T& target) const {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (data[mid] == target) return mid;
        if (data[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

template <typename T>
void OrderedArray<T>::clear() {
    size = 0;
}

// ================= Explicit Template Instantiations =================
template class OrderedArray<int>;
template class OrderedArray<float>;
template class OrderedArray<double>;

#endif
