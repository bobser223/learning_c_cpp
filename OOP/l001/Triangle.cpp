//
// Created by Volodymyr Avvakumov on 19.08.2024.
//
#include <iostream>
#include <cmath>

#include "Figure.h"

using namespace std;

class Triangle : public Figure{
public:

    int a, b, c;

    Triangle(int a_a, int a_b, int a_c){
        a = a_a;
        b = a_b;
        c = a_c;
    };

    int perimeter() const override {
        return a + b + c;
    };

    double area() const override {
        double p = perimeter() / 2;
        return sqrt(p*(p - a)*(p - b)*(p - c));
    }

    void printMe() override {
        cout << "I am triangle, my a = " << a << ", b = " << b << ", c = " << c << endl;
    };

};


//int main(){
//    Triangle tr(6, 7, 8);
//
//    cout << tr.perimeter() << endl;
//    cout << tr.area() << endl;
//    tr.printMe();
//}