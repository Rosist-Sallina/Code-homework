#pragma once
#include "abstract_compare.h"
#include <vector>
#include <algorithm>
#include "compare.h"

template<class T> class PriorityQueue {
public:
    AbstractCompare<T> *_cmp;
    PriorityQueue(AbstractCompare<T> *_cmp){
        this->_cmp = _cmp;
    };

    std::vector<T> data;

    bool empty(){
        return data.empty();
    };
    int size(){
        return data.size();
    };
    void push(T element){
        data.push_back(element);
        int i = data.size() - 1;
        while (i > 0) {
            if (_cmp->compare(data[i], data[i - 1])) {
				std::swap(data[i], data[i - 1]);
				i--;
            }
            else
                break;
        }
    };
    void pop(){
        if(data.size() == 1){
            data.pop_back();
            return;
        }
        data.erase(data.begin());
    };
    T top(){
        return data[0];
    };
};