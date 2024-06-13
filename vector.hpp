#ifndef GEN_H
#define GEN_H
#include <cstddef>
#include <ostream>
#pragma once
#include <iostream>
using namespace std;

template<class T> class vect {
    private:
        int size;
        T* data;
        friend ostream& operator<<(ostream& os, const vect<int>& obj);
    public:
        vect();
        vect(int size);
        vect(int size, T start);
        vect(vect<T> &b);
        vect(vect<T> &&b);
        ~vect();
        int getsize();
        T& operator[](int index);
        void push_back(T val);
        T pop_back();
        void insert(int index, T val);
        void remove(int index);
        void print();
        vect<T> operator+(vect<T>&);
        vect<T> operator*(int);
        void operator+=(vect<T>&);
        void operator+=(T&);
        void operator*=(int);
        bool operator<(vect<T>&);
        bool operator>(vect<T>&);
        bool operator==(vect<T>&);
        bool operator>=(vect<T>&);
        bool operator<=(vect<T>&);
        void operator=(vect<T>&);
        void operator=(vect<T>&&);
};

template <class T>
vect<T>::vect() {
    size=0;
    data = new T[size];
}

template <class T>
vect<T>::vect(vect<T> &b) {
    size = b.getsize();
    data = new T[size];

    for (int i=0; i<size; i++) {
        data[i] = b.data[i];
    }
}

template <class T>
vect<T>::vect(int size) {
    this->size = size;
    data = new T[size];
}
template <class T>
vect<T>::vect(int size, T start) {
    this->size = size;
    data = new T[size];
    for (int i=0; i<size; i++) {
        data[i] = start;
    }
}
template <class T>
vect<T>::~vect(){
    delete[] data; 
}

template <class T>
vect<T>::vect(vect<T>&& tmp) : data(tmp.data), size(tmp.size) {
    tmp.data = nullptr;
    tmp.size = 0;
}

template <class T>
ostream& operator<<(ostream& os, vect<T>& obj) {
    for (int i =0; i<obj.getsize(); i++) {
        os<<obj[i]<<' ';
    }
    return os;
}

template <class T>
void vect<T>::operator=(vect<T>& tmp) {
    delete this->data;
    size = tmp.size;
    data = new T[size];
    for (int i = 0; i< size; i++) {
        data[i] = tmp.data[i];
    }
}

template <class T>
void vect<T>::operator=(vect<T>&& tmp)
{
    delete this->data;
    data = tmp.data, size = tmp.size;  
    tmp.size = 0;
    tmp.data = nullptr;
}

template<class T>
vect<T> vect<T>::operator+(vect<T>& b) {
    vect<T> c(b.size+size);
    for (int i = 0; i<size; i++) {
        c[i] = data[i];
    }
    for (int i = 0; i<b.size; i++) {
        c[i+size] = b[i];
    }
    return c;
}

template<class T>
void vect<T>::operator+=(vect<T>& b) {
    for (int i = 0; i<b.size; i++) {
        this->push_back(b[i]);
    }
}

template<class T>
void vect<T>::operator+=(T& elem) {
    this->push_back(elem);
}

template <typename T>
vect<T> vect<T>::operator*(int x) {
    int nsize = size*x;
    vect<T> res(nsize);
    for (int i=0; i<nsize; i++) {
        res[i] = data[i%size];
    }
    return res;
}

template <typename T>
void vect<T>::operator*=(int x) {
    int nsize = size*x;
    T* tmp = new T[nsize];
    for (int i=0; i<nsize; i++) {
        tmp[i] = data[i%size];
    }
    delete data;
    data= tmp;
    size = nsize;
}

template<class T>
bool vect<T>::operator<(vect<T>& b) {
    return (size < b.size) ? true : false;
}
template<class T>
bool vect<T>::operator>(vect<T>& b) {
    return (size > b.size) ? true : false;
}
template<class T>
bool vect<T>::operator==(vect<T>& b) {
    return (size == b.size) ? true : false;
}
template<class T>
bool vect<T>::operator<=(vect<T>& b) {
    return (size <= b.size) ? true : false;
}
template<class T>
bool vect<T>::operator>=(vect<T>& b) {
    return (size >= b.size) ? true : false;
}

template <class T>
int vect<T>::getsize() {
    return this->size;
}

template <class T>
T& vect<T>::operator[](int index) {
    return data[index];
}

template <class T>
void vect<T>::push_back(T val) {
    T* tmp = new T[size + 1];
    for (int i=0; i<size; i++) {
        tmp[i] = data[i];
    }
    tmp[size] = val;
    size++;
    delete[] data;
    data = tmp;
}

template <class T>
T vect<T>::pop_back() {
    T* tmp= new T[size -1];
    for (int i=0; i<size-1; i++) {
        tmp[i] = data[i];
    }
    T pop_obj = data[size-1];
    delete[] data;
    data = tmp;
    size--;
    return pop_obj;
}

template <class T>
void vect<T>::insert(int index, T val) {
    T* tmp = new T[size +1];
    for (int i =0;i<size+1; i++){
        if (i < index)
            tmp[i] = data[i];
        else if (i == index)
            tmp[index] = val;
        else 
            tmp[i] = data[i-1];
    }
    delete[] data;
    data = tmp;
    size++;
}

template <class T>
void vect<T>::remove(int index) {
    T* tmp = new T[size -1];
    for (int i=0;i<size;i++) {
        if (i<index)
            tmp[i]=data[i];
        else if (i>index)
            tmp[i-1]= data[i];
    }
    delete[] data;
    data=tmp;
    size--;
}

template <class T>
void vect<T>::print() {
    if (size == 0) {
        cout<<"Vacio.\n";
        return;
    }
    for (int i=0; i<size; i++) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

#endif
