//
// Created by Volodymyr Avvakumov on 22.09.2024.
//

#include <iostream>
#include <bitset>
#include <cstdint>

int max_one(int num){
    int max_one_pos = 0;
    int counter = 0;
    while (num > 0){
        if (num % 2 == 1){
            max_one_pos = counter;
        }

        num = num >> 1;
        counter ++;
    }

    return max_one_pos;
}

int main(){
    int a = 130;
    std::cin >> a;
//    std::cout << a << std::endl;
    a = (uint8_t)a;
    std::cout << a << std::endl;
    std::cout << "a bit = " <<  std::bitset<8>(a)<< std::endl;
    int boss_1 = max_one(a);
//    std::cout << "boss_1 bit = " << boss_1 << std::endl;
    uint8_t b = a << (8 - boss_1);
//    std::cout << "b bit = " << std::bitset<8>(b)<< std::endl;
    b = b >> (8 - boss_1 - 1);

//    std::cout << "b bit = " << std::bitset<8>(b)<< std::endl;
    uint8_t c = a >> boss_1;
//    std::cout << "c bit = " << std::bitset<8>(c)<< std::endl;
    std::cout << "result bit = " << std::bitset<8>((b | c))<< std::endl;
    std::cout << (b | c) << std::endl;
}