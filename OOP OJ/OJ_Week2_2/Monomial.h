#include <iostream>
#include <string>

class Monomial
{
private:
    int coe;
    int deg;
public:
    Monomial();
    Monomial(int _c, int _d);
    friend std::istream &operator>>(std::istream &is, Monomial &x);
    friend std::ostream &operator<<(std::ostream &os, const Monomial &x);
    Monomial operator+(const Monomial &x);
    Monomial operator-(const Monomial &x);
    Monomial operator*(const Monomial &x);
    Monomial operator/(const Monomial &x);
    int definite_integral(const int a, const int b);
    Monomial derive();
    int get_val(int x);
    //TODO
};