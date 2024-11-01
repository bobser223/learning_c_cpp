//
// Created by Volodymyr Avvakumov on 01.11.2024.
//
#include <iostream>
using namespace std;
struct A {virtual ~A() = default;}; // smaller
struct B: public A {virtual ~B() = default;}; // bigger

void static_cast_example(){
    double d = 54.543534;
    int i = static_cast<int> (d);
    cout << i << endl;
    const int& j = static_cast<const int&>(d);
    cout << j << endl;

    void* ptr = static_cast<void*>(&d);
//    d = static_cast<double>(*ptr);
    cout << endl;
    A* a1 = new A();
    B* b1 = static_cast<B*>(a1); //downcast фу фу фу

    A* a2 = new B();
    B* b2 = static_cast<B*>(a2); //downcast фу фу фу

    B* b3 = new B();
    A* a3 = static_cast<A*>(b3); // upcast ok


    delete a1, a2, b3;
}

void dynamic_cast_example(){

    A* a1 = new A();
    B* b1 = dynamic_cast<B*>(a1); //downcast ok but  фу фу фу
    cout << b1 << endl;

    A* a2 = new B();
    B* b2 = dynamic_cast<B*>(a2); //downcast ok but  фу фу фу
    cout << b2 << endl;

    B* b3 = new B();
    A* a3 = static_cast<A*>(b3); // upcast ok
    cout << b3 << endl;

    A a4;
    B& b4 = dynamic_cast<B&>(a4); //downcast фу фу фу
//    cout << b4 << endl;


    delete a1, a2, b3;
}

int main(){
    static_cast_example();
    dynamic_cast_example();
}