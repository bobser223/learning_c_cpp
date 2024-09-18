//
// Created by Volodymyr Avvakumov on 16.09.2024.
// l

#include <iostream>


double const EPSILON = 0.00000000001;

using namespace std;

double absolute(double x){
    if (x < 0)
        return (-1) * x;
    else
        return x;
}

double seq(double x){
    double sum = 1;
    long double an = 1;
    long double xn = 1;
    long double highF = 1, lowF = 1;
    int i = 1;
    while(absolute(an) >= EPSILON){
        xn *= x;
        highF *= (2*i - 1);
        lowF *= (2*i);
        an = (-1)*(highF/lowF)*xn;
        sum += an;
        i++;
        if (absolute(an) <= EPSILON){
            break;
        }
    }
    return sum;

}

int main(){
    double x;
    cin >> x;
    cout << seq(x) << endl;
    return 0;
}
