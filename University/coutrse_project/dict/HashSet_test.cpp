//
// Created by Volodymyr Avvakumov on 27.10.2024.
//
#include <iostream>
#include "LinkedList.h"
#include "HashSet.h"

int main(){
    HashSet<int> set;
    for (int i = 10; i < 100; i ++){
        set.add(i);
        std::cout << set << std::endl;
    }
    std::cout << set << std::endl;
    set.pop(10);
    std::cout << set << std::endl;
    set.add(10);
    set.add(10);
    std::cout << set << std::endl;
    std::cout << set.is_in(5) << std::endl;
    std::cout << set.is_in(89) << std::endl;



    return 0;

}