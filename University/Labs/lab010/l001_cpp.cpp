//
// Created by Volodymyr Avvakumov on 30.09.2024.
//
#include <iostream>
#include <cstdlib>

using namespace std;

void print(int* a,int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);

    }
}

void input(int* a,int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];

//        scanf("%d", &a[i]);
    }
}


int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    int* x = new int(10);
    input(a, n);
    print(a, n);

    delete[] a;
    delete x;
}

