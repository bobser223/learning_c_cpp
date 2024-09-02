//
// Created by Volodymyr Avvakumov on 16.08.2024.
//
#include <iostream>

using namespace std;

int main(){
    char str1[] = "Hello";
    char str2[] = ", world";
    cout << str1 << "<=======>" << str2 << endl;
    strcat(str1, str2);
    cout<< str1 << str2 << endl;

    string str3 = "Hello";
    string str4 = ", world!";
    cout << str3 + str4 << endl;
    return 0;
}