//
// Created by Volodymyr Avvakumov on 20.08.2024.
//
#include <iostream>
#include <cmath>

#include "Figure.h"

using namespace std;

class Circle : public Figure{
public:
    int r;

    explicit Circle(int a_r){
        r = a_r;
    };

    int perimeter() const override{
        return 2*M_PI*r;
    };

    double area() const override{
        return M_PI*pow(r, 2);
    };


    void printMe() override {
        cout << "I am circle, my r = " << r << endl;
    };
};