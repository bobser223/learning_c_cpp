//
// Created by Volodymyr Avvakumov on 16.09.2024.
// e
#include <iostream>

using namespace std;

double seq(int n){
    double a0 = 1, ak;
    double sum = 1;
    double x2 = 1;
    long fact = 1;
    for (int k= 1; k <= n; k++){
        ak = k * a0 + 1.0 / k;
        x2 = x2*2;
        fact *= k;
        sum += (x2/fact) * ak;


    }
    return sum;
}


int main(){
    int n;
    cin >> n;
    cout << seq(n) << endl;

    return 0;
}