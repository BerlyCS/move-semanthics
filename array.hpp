#ifndef GEN_STATIC_ARRAY_H
#define GEN_STATIC_ARRAY_H
#include <bits/fs_fwd.h>
#pragma once

#include <iostream>

template <typename T, int SIZE>
class Array {
    private:
        int size;
        T* data;
    public:
        Array<T,SIZE>();
        Array<T, SIZE>(T);
        Array<T,SIZE>(Array<T, SIZE> &b);
        ~Array();
        Array<T, SIZE>(Array<T, SIZE>&& tmp);
        T get(int index);
        void set(int index, T val);
        int getsize();
        void print();
        T& operator[](int index);
        void operator=(Array<T, SIZE>&);
        void operator=(Array<T, SIZE>&&);
        bool operator<(Array<T, SIZE>&);
        bool operator>(Array<T, SIZE>&);
        bool operator==(Array<T, SIZE>&);
        bool operator>=(Array<T, SIZE>&);
        bool operator<=(Array<T, SIZE>&); 
};
template <typename T, int SIZE>
Array<T, SIZE>::Array(Array<T, SIZE>&& tmp) : data(tmp.data), size(tmp.size) {
    tmp.data = nullptr;
    tmp.size = 0;
}
template <typename T, int SIZE>
Array<T,SIZE>::Array() {
    size = SIZE;
    data = new T[size];
}

template <typename T, int SIZE>
Array<T,SIZE>::Array(T start) {
    size = SIZE;
    data = new T[size];
    for (int i=0; i<size; i++) {
        data[i] = start;
    }
}

template <typename T, int SIZE>
Array<T,SIZE>::Array(Array<T, SIZE> &b) {
    size = b.getsize();
    data = new T[size];
    for (int i=0; i<size; i++) {
        data[i] = b.get(i);
    }
}
template <class T, int SIZE>
T& Array<T,SIZE>::operator[](int index) {
    return data[index];
}

template <class T, int SIZE>
void Array<T,SIZE>::operator=(Array<T, SIZE>&& other) {
    delete data;
    data = other.data;
    other.data = nullptr;
}

template<class T, int SIZE>
bool Array<T,SIZE>::operator<(Array<T, SIZE>& b) {
    return (size < b.size) ? true : false;
}
template<class T, int SIZE>
bool Array<T,SIZE>::operator>(Array<T,SIZE>& b) {
    return (size > b.size) ? true : false;
}
template<class T, int SIZE>
bool Array<T,SIZE>::operator==(Array<T,SIZE>& b) {
    return (size == b.size) ? true : false;
}
template<class T, int SIZE>
bool Array<T,SIZE>::operator<=(Array<T,SIZE>& b) {
    return (size <= b.size) ? true : false;
}
template<class T, int SIZE>
bool Array<T,SIZE>::operator>=(Array<T,SIZE>& b) {
    return (size >= b.size) ? true : false;
}
template <typename T, int SIZE>
Array<T, SIZE>::~Array() {
    delete[] data;
}

template <typename T, int SIZE>
T Array<T, SIZE>::get(int index) {
    return data[index];
}

template <typename T, int SIZE>
int Array<T, SIZE>::getsize() {
    return this->size;
}

template <typename T, int SIZE>
void Array<T, SIZE>::print() {
    for (int i=0; i<size; i++) {
        std::cout<<data[i]<<' ';
    }
    std::cout<<std::endl;
}

template <typename T, int SIZE>
void Array<T, SIZE>::set(int index, T val) {
    if (index < 0 || index >= size) 
        return;

    data[index] = val;
}

#endif
