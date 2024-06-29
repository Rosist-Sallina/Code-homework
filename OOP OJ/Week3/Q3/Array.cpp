#include "Array.h"

Array::Array(int len){
    this->len = len;
    this->arr = new Node[len];
};

Array::Array(const Array &y){
    this-> len = y.len;
    for(int i = 0; i < len; i++){
        this->arr[i] = y.arr[i];
    }
}

Array::Array(Array &&y){
    this->len = y.len;
    this->arr = y.arr;
    y.arr = nullptr;
}

Array::~Array(){
    delete[] arr;
}

Array& Array::operator=(const Array &y){
    if(this == &y){
        return *this;
    }
    this->len = y.len;
    for(int i = 0; i < len; i++){
        this->arr[i] = y.arr[i];
    }
    return *this;
}

Array& Array::operator=(Array &&y){
    if(this == &y){
        return *this;
    }
    delete[] arr;
    this->len = y.len;
    this->arr = y.arr;
    y.arr = nullptr;
    return *this;
}

Node& Array::operator[](int i){
    return arr[i];
}

const Node& Array::operator[](int i) const{
    return arr[i];
}

