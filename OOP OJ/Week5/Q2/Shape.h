#include <iostream>
#include <memory>
#pragma once

template <class RealShape> class Shape {
protected:
    int a, b;
public:
    static int create;
    static int alive;
    RealShape *test;
    Shape(int a, int b): a(a), b(b){
        this->test = new RealShape(a, b);
        create++;
        alive++;
    };
    ~Shape(){
        delete test;
        alive--;
    };

    std::string type(){
        return static_cast<RealShape*>(this)->typeImpl();
    };
    int area(){
        return static_cast<RealShape*>(this)->areaImpl();

    };
    std::shared_ptr<Shape> print(){
        std::cout << "Area of [" << type() << "]: ["<< area() <<"]";
        return std::shared_ptr<Shape>(this);
    };
    std::shared_ptr<Shape> zoom(int k){
        a *= k;
        b *= k;
        return std::shared_ptr<Shape>(this);
    };
    static int getCreate(){
        return create;
    };
    static int getAlive(){
        return alive;
    };

};

template <class RealShape> int Shape<RealShape>::create = 0;
template <class RealShape> int Shape<RealShape>::alive = 0;

class Triangle:public Shape<Triangle> {
    public:
        Triangle(int a, int b): Shape<Triangle>(a, b){};
        std::string typeImpl(){
            return "Triangle";
        };
        int areaImpl(){
            return a*b/2;
        };
};

class Rectangle:public Shape<Rectangle> {
    public:
        Rectangle(int a, int b): Shape<Rectangle>(a, b){};
        std::string typeImpl(){
            return "Rectangle";
        };
        int areaImpl(){
            return a*b;
        };
};

