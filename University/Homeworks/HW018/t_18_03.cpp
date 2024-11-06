//
// Created by Volodymyr Avvakumov on 06.11.2024.
//
#include <iostream>

#include "t_18_03.h"

int main(){
    BlackBox<int> bb;
    bb.push(3);
    bb.push(4);
    bb.push(5);
    for (int i = 0; i < 4; i++){
        std::cout << bb.xpop() << std::endl;
    }

    for (int i = 0; i < 4; i++){ // trowing error
        std::cout << bb.pop() << std::endl;
    }
    BlackBox<char> bb2("qwerty", 6);
    for (int i = 0; i < 7; i++){
        std::cout << bb2.xpop() << std::endl;
    }

    for (int i = 0; i < 7; i++){ // trowing error
        std::cout << bb2.pop() << std::endl;
    }

    return 0;
}

