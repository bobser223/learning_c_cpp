//
// Created by Volodymyr Avvakumov on 23.09.2024.
//
#include <iostream>
#include <bitset>

using namespace std;

void test(){
    uint32_t  x = 0xF070301;
    cout << bitset<32>(x) << endl;
    uint8_t* ptr = (uint8_t*) &x;
//    printf("%p\n", ptr);
//    printf("%p\n", ptr + 1);
    for (int i = -3; i < 4; i++) {
        cout << bitset<8>(*(ptr + i)) << ' ';
    }
//    cout << (uint16_t)*(ptr) << endl;

}

void endian_1(){
    uint32_t x = 1;
    uint8_t* ptr = (uint8_t*) &x;
    if (*ptr)
        cout << "little endian" << endl;
    else if (*(ptr + 3))
        cout << "big endian" << endl;
    else
        cout << "middle indian" << endl;

}


int main(){
    test();
    endian_1();
    return 0;
}