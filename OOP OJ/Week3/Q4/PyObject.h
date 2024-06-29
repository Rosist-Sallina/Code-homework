#include "test.h"
#include<iostream>

#pragma once

class PyObject{
    public:
        struct Data{
            char c;
            int i;
            double d;
        } data;
        Test* t;
        bool flag = 0;

        PyObject(){
            t = nullptr;
        }
        PyObject(int i){
            data.i = i;
            t = nullptr;
        }
        PyObject(char c){
            data.c = c;
            t = nullptr;
        }
        PyObject(double d){
            data.d = d;
            t = nullptr;
        }
        ~PyObject(){
            if(t != nullptr && flag){
                delete t;
            }
        }

        operator char() const{
            return data.c;
        };
        operator int() const{
            return data.i;
        };
        operator double() const{
            return data.d;
        };
        operator Test& () const {
            return *t;
        }


        PyObject operator=(const char c){
            data.c = c;
            std::cout << "PyObject got a value\n";
            return *this;
        };
        PyObject operator=(const int i){
            data.i = i;
            std::cout << "PyObject got a value\n";
            return *this;
        };
        PyObject operator=(const double d){
            data.d = d;
            std::cout << "PyObject got a value\n";
            return *this;
        };
        // PyObject &operator=(Test* t){
		// 	this->t = t;
		// 	std::cout << "PyObject got a value\nBorrowing\n";
		// 	return *this;
		// };
        PyObject& operator=(Test && t1) {
            std::cout << "PyObject got a value\n";
            t = new Test(std::move(t1));
            std::cout << "Owning\n";
            flag = 1;
            return *this;
        }
        PyObject& operator =(Test &t1) {
            std::cout << "PyObject got a value\nBorrowing\n";
            this->t = &t1;
            flag = 0;
            return *this;
        }
        PyObject& operator =(const PyObject *p){
			t = p->t;
			std::cout << "PyObject got a value\nBorrowing\n";
            flag = 0;
			return *this;
		}
        PyObject& operator =(PyObject& p) {
            if(p.flag){
                flag = 1;
                std::cout << "PyObject got a value\nBorrowing\n";
                p.flag = 0;
                t = p.t;
            }
            else{
                flag = 0;
			    std::cout << "PyObject got a value\nBorrowing\n";
                t = p.t;
                p.t = nullptr;
            }
			return *this;
        }
};

// #include "test.h"
// #include <iostream>
// #include <memory>

// class PyObject {
// public:
//     enum class Type { Char, Int, Double, TestPtr };
//     union Value {
//         char c;
//         int i;
//         double d;
//         Test* t;

//         Value() : c('\0') {} // ��ʼ��Ϊ��ֵ������δ������Ϊ
//         ~Value() {}  // �Զ���������Ϊ�˸�������Test��׼��
//     };

// private:
//     Type type;
//     Value value;
//     bool ownsTest = false;

// public:
//     PyObject() : type(Type::Int), value() {}
//     ~PyObject() {
//         if (ownsTest && type == Type::TestPtr) {
//             delete value.t;
//         }
//     }

//     PyObject& operator=(char c) {
//         clear();
//         type = Type::Char;
//         value.c = c;
//         std::cout << "PyObject got a value\n";
//         return *this;
//     }

//     PyObject& operator=(int i) {
//         clear();
//         type = Type::Int;
//         value.i = i;
//         std::cout << "PyObject got a value\n";
//         return *this;
//     }

//     PyObject& operator=(double d) {
//         clear();
//         type = Type::Double;
//         value.d = d;
//         std::cout << "PyObject got a value\n";
//         return *this;
//     }

//     PyObject& operator=(Test* t) {
//         clear();
//         type = Type::TestPtr;
//         value.t = t;
//         std::cout << "PyObject got a value\nBorrowing\n";
//         return *this;
//     }

//     PyObject& operator=(Test& t1) {  // ע�⣬��������ǰ�ֵ����
//         if (ownsTest) {
//             delete value.t;
//         }
//         value.t = new Test(std::move(t1));  // �����ƶ�����һ���¶���
//         ownsTest = true;
//         std::cout << "PyObject got a value\nOwning\n";
//         return *this;
//     }

//     PyObject& operator=(Test&& t) {
//         clear();
//         type = Type::TestPtr;
//         value.t = new Test(std::move(t));
//         ownsTest = true;
//         std::cout << "PyObject got a value\nOwning\n";
//         return *this;
//     }

//     operator char() const {
//         if (type == Type::Char) return value.c;
//         throw std::bad_cast();
//     }

//     operator int() const {
//         if (type == Type::Int) return value.i;
//         throw std::bad_cast();
//     }

//     operator double() const {
//         if (type == Type::Double) return value.d;
//         throw std::bad_cast();
//     }

//     operator Test&() const {
//         if (type == Type::TestPtr && value.t != nullptr) return *value.t;
//         throw std::bad_cast();
//     }

// private:
//     void clear() {
//         if (ownsTest && type == Type::TestPtr) {
//             delete value.t;
//             ownsTest = false;
//         }
//         value = Value();  // ����������
//     }
// };
