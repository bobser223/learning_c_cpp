//
// Created by Volodymyr Avvakumov on 16.08.2024.
//

#include <iostream>

using namespace std;

template <typename T>
void print(T value, string end = "/n"){
    if (end == "/n"){
        cout << value << endl;
    } else if (end == ""){
        cout << value;
    } else if (end == " "){
        cout << value << end;
    } else {
        cout << "you are monkey, order your banana :)" << endl;
    }

}
