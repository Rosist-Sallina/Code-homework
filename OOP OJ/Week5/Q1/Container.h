#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

#pragma once

using std::vector;
using std::map;

template<class A> struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
    bool operator < (const Point<A> b) const {
        return this->pos < b.pos;
    }
    bool operator > (const Point<A> b) const {
        return this->pos > b.pos;
    }
};

template<class A, class C> class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A> class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    
    public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }

    A* find(Pos p) {
        static bool flag = 1;
        if(flag) {
            flag = 0;
            std::sort(base.begin(), base.end());
        }
        auto t = std::lower_bound(base.begin(), base.end() , Point<A>(p, A()));
        if(t == base.end() || t->pos != p) return NULL;
        return &(t->value);
    }
};

template <class A> class Container<A , map<Pos , A> > : public BasicContainer<A> {
    map<Pos, A> base;
    
    public:
    void insert(const Pos &p, const A &v) {
        base[p] = v;;
    }

    A* find(Pos p) {
        auto t = base.find(p);
        if(t == base.end()) return NULL;
        return &(t->second);
    }
};

#endif
