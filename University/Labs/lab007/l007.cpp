//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    uint8_t x = 0b00111000;
    // x - 1 = 0b0011011
    // x & (x - 1) = 0b001100000 // прибирає наймолодший біт
//     (x & (x - 1)) > 0 // дасть false якщо х - 0, або степінь двійки
//
//     b ef
//     -y = ~y + 1
    uint8_t y = 0b00111000;
    cout << bitset<8>(y) << endl;
    cout << bitset<8>(-y) << endl;
    cout << bitset<8>(~y + 1) << endl;
    cout << bitset<8>(y & (-y)) << endl;
    return 0;
}