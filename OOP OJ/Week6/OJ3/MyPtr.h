#pragma once
#include <iostream>
using namespace std;
#include <memory> 

struct Counter {
public:
    int s, w;
    Counter(int _s = 0, int _w = 0) : s(_s), w(_w) {}
};


template <class T> class MyWeakPtr;
template <class T> class MySharedPtr {
private:
    T *data;
    Counter *refCount;
    void release(){
        if(refCount == nullptr || data == nullptr) {
            return;
        }
        refCount->s--;
        if(refCount->s == 0) {
            std::cout << "data released.\n";
            delete data;
            delete refCount;
        }
    };
public:
    MySharedPtr();
    MySharedPtr(T *p);
    MySharedPtr(MySharedPtr<T> &&sp);
    MySharedPtr(const MyWeakPtr<T> &wp);
    MySharedPtr(const MySharedPtr<T> &sp);
    ~MySharedPtr();
    MySharedPtr<T>& operator= (MySharedPtr<T> &&sp);
    MySharedPtr<T>& operator= (const MySharedPtr<T> &sp);

    int use_count();
    T& operator* ();
    T* operator-> ();

    friend class MyWeakPtr<T>;
};

template <class T> MySharedPtr<T>::MySharedPtr() {
    data = nullptr;
    refCount = new Counter(1, 0);
    if(refCount == nullptr) {
        refCount = new Counter(1, 0);
    }
    std::cout << "my_sptr constructed.\n";
}

template <class T> MySharedPtr<T>::MySharedPtr(T *p) {
    data = p;
    refCount = new Counter(1, 0);
    std::cout << "my_sptr constructed.\n";
}

template <class T> MySharedPtr<T>::MySharedPtr(MySharedPtr<T> &&sp) {
    data = sp.data;
    refCount = sp.refCount;
    sp.data = nullptr;
    sp.refCount = nullptr;
    std::cout << "my_sptr constructed.\n";
}

template <class T> MySharedPtr<T>::MySharedPtr(const MyWeakPtr<T> &wp) {
    data = wp.data;
    refCount = wp.refCount;
    refCount->s++;
    std::cout << "my_sptr constructed.\n";
}

template <class T> MySharedPtr<T>::MySharedPtr(const MySharedPtr<T> &sp) {
    data = sp.data;
    refCount = sp.refCount;
    refCount->s++;
    std::cout << "my_sptr constructed.\n";
}

template <class T> MySharedPtr<T>::~MySharedPtr() {
    std::cout << "my_sptr destructed.\n";
    release();
}

template <class T> MySharedPtr<T>& MySharedPtr<T>::operator= (MySharedPtr<T> &&sp) {
    std::cout << "my_sptr updated\n";
    release();
    data = sp.data;
    refCount = sp.refCount;
    sp.data = nullptr;
    sp.refCount = nullptr;
    return *this;
}

template <class T> MySharedPtr<T>& MySharedPtr<T>::operator= (const MySharedPtr<T> &sp) {
    std::cout << "my_sptr updated\n";
    release();
    data = sp.data;
    refCount = sp.refCount;
    refCount->s++;
    return *this;
}

template <class T> int MySharedPtr<T>::use_count() {
    return refCount->s;
}

template <class T> T& MySharedPtr<T>::operator* () {
    return *data;
}

template <class T> T* MySharedPtr<T>::operator-> () {
    return data;
}


template <class T>
class MyWeakPtr {
private:
    Counter *refCount;
    T *data;
    void release();
public:
    MyWeakPtr();
    MyWeakPtr(MySharedPtr<T> &sp);
    MyWeakPtr(const MyWeakPtr &wp);
    MyWeakPtr(MyWeakPtr &&wp);
    ~MyWeakPtr();

    MyWeakPtr<T>& operator= (const MyWeakPtr<T> &wp);

    MyWeakPtr<T>& operator= (const MySharedPtr<T> &sp);

    MyWeakPtr<T>& operator= (MyWeakPtr<T> &&wp);

    bool expired();
    MySharedPtr<T> lock();

    int use_count();

    friend class MySharedPtr<T>;
};

template <class T> void  MyWeakPtr<T>::release(){
    if(refCount == nullptr || data == nullptr) {
        return;
    }
    refCount->w--;
    if(refCount->s == 0 && refCount->w == 0) {
        std::cout << "data released.\n";
        delete data;
        delete refCount;
    }

}

template <class T> MyWeakPtr<T>::MyWeakPtr() {
    refCount = new Counter(0, 1);
    data = nullptr;
    if(refCount == nullptr) {
        refCount = new Counter(0, 1);
    }
    std::cout << "my_wptr constructed.\n";
}

template <class T> MyWeakPtr<T>::MyWeakPtr(MySharedPtr<T> &sp) {
    refCount = sp.refCount;
    data = sp.data;
    refCount->w++;
    std::cout << "my_wptr constructed.\n";
}

template <class T> MyWeakPtr<T>::MyWeakPtr(const MyWeakPtr<T> &wp) {
    refCount = wp.refCount;
    data = wp.data;
    refCount->w++;
    std::cout << "my_wptr constructed.\n";
}

template <class T> MySharedPtr<T> MyWeakPtr<T>::lock() {
    if(refCount->s == 0) {
        return MySharedPtr<T>();
    }
    return MySharedPtr<T>(*this);
}

template <class T> MyWeakPtr<T>::MyWeakPtr(MyWeakPtr &&wp) {
    refCount = wp.refCount;
    data = wp.data;
    wp.refCount = nullptr;
    wp.data = nullptr;
    std::cout << "my_wptr constructed.\n";
}

template <class T> MyWeakPtr<T>::~MyWeakPtr() {
    std::cout << "my_wptr destructed.\n";
    release();
}

template <class T> MyWeakPtr<T>& MyWeakPtr<T>::operator= (const MyWeakPtr<T> &wp) {
    std::cout << "my_wptr updated\n";
    release();
    refCount = wp.refCount;
    data = wp.data;
    refCount->w++;
    return *this;
}

template <class T> MyWeakPtr<T> &MyWeakPtr<T>::operator= (const MySharedPtr<T> &sp) {
    std::cout << "my_wptr updated\n";
    release();
    refCount = sp.refCount;
    data = sp.data;
    refCount->w++;
    return *this;
}

template <class T> MyWeakPtr<T> &MyWeakPtr<T>::operator= (MyWeakPtr<T> &&wp) {
    std::cout << "my_wptr updated\n";
    release();
    refCount = wp.refCount;
    data = wp.data;
    wp.refCount = nullptr;
    wp.data = nullptr;
    return *this;
}

template <class T> bool MyWeakPtr<T>::expired() {
    return refCount->s == 0;
}

template <class T> int MyWeakPtr<T>::use_count() {
    return refCount->s;
}
