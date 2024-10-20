//
// Created by Volodymyr Avvakumov on 18.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    fstream f;
    f.open("inp01.txt", f.in);
//    while (f.good()){
//
//    }
    string exp;
    getline(f, exp);
    stringstream ss(exp);
    char operation;
    float first_num, curr_num;
    ss >> first_num;
    while(ss >> operation >> curr_num){
        if (operation == '+'){
            first_num += curr_num;
        } else {
            first_num -= curr_num;
        }
    }
    cout << first_num << endl;

}

void foo(){
    fstream f;
    f.open("inp01.txt", f.in);
    while (f.good()){
}