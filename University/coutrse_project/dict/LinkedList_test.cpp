//
// Created by Volodymyr Avvakumov on 26.10.2024.
//
#include <iostream>
#include "LinkedList.h"

int main(){
    LinkedList<int> lst;
    for (int i = 0; i < 10; i ++) {
        lst.add(i);
        std::cout << lst << std::endl;
    }
    std::cout << lst.is_in(4) << std::endl;
    lst.pop(4);
    std::cout << lst << std::endl;
    std::cout << lst.is_in(4) << std::endl;

    LinkedList<char> lst2;
    std::string str("enuireuifjerjibfuyerihfijrbeuyfhuireojbfuyireofe");
    for(char ch: str){
        lst2.add(ch);
    }
    std::cout << lst2 << std::endl;



    return 0;
}



