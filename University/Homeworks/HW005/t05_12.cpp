//
// Created by Volodymyr Avvakumov on 16.09.2024.
// a

#include <iostream>

using namespace std;

double absolute(double x){
    if (x < 0)
        return (-1) * x;
    else
        return x;
}

double seq(double n){
    double sum = 128.25, an = 121.5;
    double a1 = 2, a2 = 1, ak;
    double b1 = 1, b2 = 0, bk;
    long pow3 = 243;
    for(int k = 3; k < n; k++ ){
        bk = 2*b2 + a2;
        ak = a2/(k+1) + a1 + bk;
        pow3 *= 9;
        an = pow3 / (bk * ak + 1);
        sum += an;
        b1 = b2;
        b2 = bk;
        a1 = a2;
        a2 = ak;
    }


    return sum;

}

int main(){
    int n;
    cin >> n;
    cout << seq(n) << endl;
    return 0;
}

