//
// Created by Volodymyr Avvakumov on 22.11.2024.
//
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), [](char c){return toupper(c);});
    cout << str;
}