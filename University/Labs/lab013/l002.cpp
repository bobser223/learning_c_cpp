//
// Created by Volodymyr Avvakumov on 11.10.2024.
//
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using  namespace std;

int main(){
    ifstream finp("Labs/lab013/input.txt");
    ofstream fout("Labs/lab013/output.txt");
    if (!finp.is_open())
        exit(1);

    if (!fout.is_open())
        exit(2);
    while (!finp.eof()){
        int n;
        finp >> n;
        if (!finp.good()){
            break;
        }
        fout << sqrt(n) << " ";
    }
    finp.close();
    fout.close();
    return 0;
}