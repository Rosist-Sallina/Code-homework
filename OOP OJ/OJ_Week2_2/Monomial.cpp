#include<iostream>
#include<string>
#include<math.h>
#include"Monomial.h"

using namespace std;

Monomial::Monomial()
{
    coe = 0;
    deg = 0;
}

Monomial::Monomial(int _c, int _d)
{
    coe = _c;
    deg = _d;

    if(coe == 0){
        deg = 0;
    }
}

istream &operator>>(istream &is, Monomial &x)
{
    string temp;
    is >> temp;
    string temp_coe;
    string temp_deg;

    for(auto i : temp){
        if(i == 'x'){
            break;
        }
        temp_coe += i;
    }

    for(auto i = temp.find('^') + 1; i < temp.size(); i++){
        temp_deg += temp[i];
    }

    x.coe = stoi(temp_coe);
    x.deg = stoi(temp_deg);

    return is;
}

Monomial Monomial::operator+(const Monomial &x){
    Monomial temp;
    temp.coe = coe + x.coe;
    temp.deg = deg;
    return temp;
}

Monomial Monomial::operator-(const Monomial &x){
    Monomial temp;
    temp.coe = coe - x.coe;
    temp.deg = deg;
    return temp;
}

Monomial Monomial::operator*(const Monomial &x){
    Monomial temp;
    temp.coe = coe * x.coe;
    temp.deg = deg + x.deg;
    return temp;
}

Monomial Monomial::operator/(const Monomial &x){
    Monomial temp;
    temp.coe = coe / x.coe;
    temp.deg = deg - x.deg;
    return temp;
}

int Monomial::definite_integral(const int a, const int b){
    return coe * (pow(b, deg + 1) - pow(a, deg + 1)) / (deg + 1);
}

Monomial Monomial::derive(){
    Monomial temp;
    temp.coe = coe * deg;
    temp.deg = deg - 1;
    return temp;
}

int Monomial::get_val(int x){
    return coe * pow(x, deg);
}

ostream &operator<<(ostream &os, const Monomial &x){
    if(x.coe == 0){
        os << 0;
    }else{
        os << x.coe << "x^" << x.deg;
    }
    std::cout << std::endl;
    return os;
}

