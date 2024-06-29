# include "shape.h"
# include<cmath>
# pragma once

class Cylinder : public Shape3D{
    private:
        double radius, height;
    public:
        Cylinder(double r, double h): radius(r), height(h) {}
        
        double area() const override{
            return 2 * PI * radius * (radius + height);
        }
        double volume() const override{
            return PI * radius * radius * height;
        }
};