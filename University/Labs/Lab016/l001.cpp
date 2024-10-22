//
// Created by Volodymyr Avvakumov on 21.10.2024.
//

#include <iostream>

using namespace std;

class Rational{
private:
    int number;
    int denom;
    static int n;

public:
    Rational(int number, int denom){
        this -> number = number;
        this -> denom = denom;
    }

    void print(ostream& out = cout){
        out << number << "/" << denom;
    }

};

int main() {
    Rational r(1, 2);
    r.print();
    int* ptr = (int*) &r;

    *ptr = 8;
    cout << endl;
    r.print();
    *(ptr + 1) = 4;
    cout << endl;
    r.print();
}
