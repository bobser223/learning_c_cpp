//
// Created by Volodymyr Avvakumov on 20.08.2024.
//
#include <iostream>

#include "Figure.h"

using namespace std;

class Parallelogram : public Figure{
    int a, b, h;
public:
    Parallelogram(int i, int i2, int i3){
        a = i;
        b = i2;
        h = i3;
    }

    int perimeter() const override{
        return (a + b) * 2;
    };

    double area() const override {
        return b * h;
    };


    void printMe() override {
        cout << "I am parallelogram, my a = " << a << ", b = " << b << ", h = " << h << endl;
    };



};