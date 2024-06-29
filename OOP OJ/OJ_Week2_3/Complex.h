#pragma once
#include <iomanip>
class Complex {
    public:
    double Re, Im;

    Complex(double Re, double Im);
    Complex(double Re);
    Complex operator+(const Complex &c2);
    friend Complex operator-(const Complex &c1 , const Complex &c2);
    Complex operator*(const Complex &c2);
    Complex operator/(const Complex &c2);
    friend Complex operator-(const Complex & c);
    friend Complex operator~(const Complex & c);
    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend std::istream & operator>>(std::istream & is, Complex & c);
    //TODO
};

Complex operator"" i(unsigned long long Im);
Complex operator"" i(long double Im);
double abs(const Complex & c);