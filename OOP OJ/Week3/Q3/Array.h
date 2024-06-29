#include "Node.h"
#pragma once

class Array{
    public:
        int len;
        Node *arr;        
        Array(int len);
        Array(const Array &y);
        Array(Array &&y);
        ~Array();
        Array& operator=(const Array &y);
        Array& operator=(Array &&y);
        Node& operator[](int i);
        const Node& operator[](int i) const;
};