//
// Created by Volodymyr Avvakumov on 20.08.2024.
//
#include <iostream>

#include "Figure.h"

using namespace std;

class Rectangle : public Figure{
public:
    int a, b;

    Rectangle(int a_a, int a_b){
        a = a_a;
        b = a_b;
    };

     int perimeter() const override {
        return (a + b)*2;
    };

    double area() const override {
        return a * b;
    };

    void printMe() override {
        cout << "I am rectangle, my a = " << a << ", b = " << b << endl;
    };

};


