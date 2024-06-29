# include "shape.h"
# include<cmath>
# pragma once
class Circle : public Shape2D{
    private:
        double radius;
    public:
        Circle(double r): radius(r) {}
        
        double perimeter() const override{
            return 2 * PI * radius;
        }
        double area() const override{
            return PI * radius * radius;
        }
};