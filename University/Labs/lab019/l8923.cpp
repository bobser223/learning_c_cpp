//
// Created by Volodymyr Avvakumov on 07.11.2024.
//
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, long long int>::type
getHash(T value, int size){
    if (value < 0) {
        value = -value;
    }

    long long int result = 0;
    while (value) {
        result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
        result ^= (value & 0xFF);
        value >>= 8;
    }

    return result % size;
}

int main(){
    for (int i = -10; i < 0; i++){
        std::cout << getHash(i, 3) << std::endl;
    }
}