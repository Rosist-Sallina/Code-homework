#include<iostream>
#include"Complex.h"
#include<iomanip>
#include<cmath>

using std::cout, std::endl;

Complex complex(double Re, double Im) {
    return Complex(Re, Im);
}

Complex complex(double Re) {
    return Complex(Re , 0);
}

Complex Complex::operator+(const Complex &c2) {
    return Complex(Re + c2.Re, Im + c2.Im);
}


Complex operator-(const Complex &c1 , const Complex &c2) {
    return Complex(c1.Re - c2.Re, c1.Im - c2.Im);
}

Complex Complex::operator*(const Complex &c2) {
    return Complex(Re * c2.Re - Im * c2.Im, Re * c2.Im + Im * c2.Re);
}

Complex Complex::operator/(const Complex &c2) {
    double a = Re, b = Im, c = c2.Re, d = c2.Im;
    return Complex((a * c + b * d) / (c * c + d * d), (b * c - a * d) / (c * c + d * d));
}

Complex operator~(const Complex & c) {
    return Complex(c.Re, -c.Im);
}

double abs(const Complex & c) {
    return sqrt(c.Re * c.Re + c.Im * c.Im);
}

std::istream & operator >> (std::istream & is, Complex & c) {
    is >> c.Re >> c.Im;
    return is;
}

std::ostream & operator << (std::ostream & os, const Complex & c) {
    if (c.Re == 0 && c.Im == 0) {
        os << 0.00;
    } else if (c.Re == 0) {
        os << std::setprecision(2) << c.Im << "i";
    } else if (c.Im == 0) {
        os << std::setprecision(2) << c.Re;
    } else {
        os << std::setprecision(2) << c.Re << (c.Im > 0 ? " + " : " - ") << std::setprecision(2) << std::abs(c.Im) << "i";
    }
    return os;
}
//为虚数单位i定义字面量
Complex operator"" i(unsigned long long Im) {
    return Complex(0, Im);
    //TODO: 返回一个Complex对象
}

Complex operator"" i(long double Im) {
    return Complex(0, Im);
    //TODO: 返回一个Complex对象
}

Complex operator-(const Complex & c) {
    return Complex(-c.Re, -c.Im);
}
