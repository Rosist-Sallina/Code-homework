#pragma once

#include "abstract_compare.h"
#include "point.h"

AbstractCompare<int>* get_compare_int(int type){
    if (type == 1) {
        return new compare_int_by_num<int>();
    } else {
        return new compare_int_by_digit<int>();
    }
};
AbstractCompare<Point>* get_compare_point(int type){
    if(type == 3) {
        return new compare_point<Point>();
    } else {
        return new compare_point_by_distance<Point>();
    }
};

template <class T> class compare_int_by_num : public AbstractCompare<int> {
public:
    bool compare(int a, int b) {
        if (a < b) return true;
        return false;
    }
};

template <class T> class compare_int_by_digit : public AbstractCompare<int> {
public:
    bool compare(int a, int b) {
        if(compareDigitSums(a, b) == 1) {
            return true;
        } else if(compareDigitSums(a, b) == 0) {
            return false;
        }
        return false;
    }
};

template <class T> class compare_point : public AbstractCompare<Point> {
public:
    friend bool operator < (const Point &a, const Point &b) {
        if (a.x < b.x) return true;
        if (a.x == b.x && a.y < b.y) return true;
        return false;
    }
    friend bool operator > (const Point &a, const Point &b) {
        if (a.x > b.x) return true;
        if (a.x == b.x && a.y > b.y) return true;
        return false;
    }

    bool compare(Point a, Point b) {
        if (a<b) return true;
        return false;
    }
};

template <class T> class compare_point_by_distance : public AbstractCompare<Point> {
    public:
        friend bool operator < (const Point &a, const Point &b) {
            if (a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y) return true;
            return false;
        }
        friend bool operator > (const Point &a, const Point &b) {
            if (a.x*a.x + a.y*a.y > b.x*b.x + b.y*b.y) return true;
            return false;
        }
        bool compare (Point a, Point b) {
            if (a<b) return true;
            else if(a = b){
                if(a.x < b.x) return true;
                else if(a.x == b.x && a.y < b.y) return true;
                return false;
            }
            return false;
        }
};

int digitSum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int compareDigitSums(int num1, int num2) {
    int sum1 = digitSum(num1);
    int sum2 = digitSum(num2);

    if (sum1 < sum2) {
        return 1;
    } else {return 0;}
}
