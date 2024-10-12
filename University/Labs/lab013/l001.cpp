//
// Created by Volodymyr Avvakumov on 11.10.2024.
//

# include <iostream>
#include <cstdio>
#include <ios>
#include <iomanip>
#include <cstdlib>

using namespace std;


int main(){

    double x = 123.56789;
    cout << fixed << setprecision(2) << setw(10);
    cout << setfill('6') << left;
    cout << x << endl;
    cout.setf(ios::fixed);
    cout.width(100);
    bool b = 0;
    cout << b << endl;
    cout << boolalpha << b << endl;
    cout << noboolalpha << b << endl;
    return 0;
}