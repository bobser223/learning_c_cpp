//
// Created by Volodymyr Avvakumov on 13.09.2024.
// 2
#include <iostream>
#define a sin

using namespace std;

long fib_rec(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

long fib_cy(int n){
    int lst[n];
    lst[0] = 0;
    lst[1] = 1;
    for (int i = 2; i < n; i ++){
        lst[i] = lst[i - 2] + lst[i - 1];
    }
    return lst[n - 1];
}

long fiba(int n){
    int f0 = 0;
    int f1 = 1;
    int f2;
    for (int i = 0; i < n; i++){
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return f0;
}

int fib_b(int a){
    int f0 = 0;
    int f1 = 1;
    int f2;
    int i = 0;
    for (; f1 <= a; i++){
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return i;
}

int fib_c(int a){
    int f0 = 0;
    int f1 = 1;
    int f2;
    int i = 0;
    for (; f1 <= a; i++){
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return i + 1;
}

int fib_h(){
    int f0 = 0;
    int f1 = 1;

    int sum = 0;

    int f2;

    int i = 0;

    for (; f1 <= 1000; i++){
        sum += f1;
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return sum;
}


int main(){
//    int n;
//    cin >> n;
//
//
//    cout << fib_cy(n) << endl;
//    cout << fiba(n) << endl;
//    cout << fib_rec(n) << endl;
    int a;
    cin >> a;
//    cout << fib_b(a) << endl;
    cout << fib_c(a) << endl;
    cout << fib_h() << endl;

    return 0;
}