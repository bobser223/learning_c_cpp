//
// Created by Volodymyr Avvakumov on 16.09.2024.
// 7

#include <iostream>
#include <cmath>

using namespace std;

double func(int n){
    double a1 = 0, a2 = 1, ak;
    double b1 = 1, b2 = 0, bk;
    double sum = 6, sn = 2;
    int x2 = 4;
    for (int k = 3; k <= n; k ++){
        bk = b2 + a2;
        ak = a2/k + a1*bk;
        x2 *= 2;

        sn = x2 / (ak + bk);

        sum += sn;

        a1 = a2;
        a2 = ak;
        b1 = b2;
        b2 = bk;

    }

    return sum;
}


int main(){
    int n;
    cin >> n;
    cout << func(n) << endl;


}