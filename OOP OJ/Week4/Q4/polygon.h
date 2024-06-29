# include "shape.h"
# include <cmath>

#pragma once

class Polygon : public Shape2D{
    private:
        double n, s;
    public:
        Polygon(double n, double s): n(n), s(s) {}
        
        double perimeter() const override{
            return n * s;
        }
        double area() const override{
            return (n * s * s) / (4 * tan(PI / n));
        }
};