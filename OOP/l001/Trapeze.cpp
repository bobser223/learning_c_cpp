//
// Created by Volodymyr Avvakumov on 20.08.2024.
//
#include <iostream>

#include "Figure.h"

using namespace std;

class Trapeze : public Figure {
public:
    int a, b, c, d;
public:


    int perimeter() const override{
        return a + b + c + d;
    };

    double area() const override {
        return 0.2;
    };


    void printMe() override {
        cout << "I am trapeze, my a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;
    };



    Trapeze(int a_a, int a_b, int a_c, int a_d){
        a = a_a;
        b = a_b;
        c = a_c;
        d = a_d;
    }
};