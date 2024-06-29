#include <cmath>
#include "shape.h"
#pragma once

class Cone : public Shape3D{
    private:
        double radius, height;
    public:
        Cone(double r, double h): radius(r), height(h) {}
        
        double area() const override{
            return PI * radius * (radius + sqrt(radius * radius + height * height));
        }
        double volume() const override{
            return (PI * radius * radius * height) / 3;
        }
};