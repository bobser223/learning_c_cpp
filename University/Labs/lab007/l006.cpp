//
// Created by Volodymyr Avvakumov on 20.09.2024.
//
#include <iostream>
#include <bitset>

using namespace std;

int main(){
    uint16_t n;
//    cin >> n;
    n = 0b0011110001111101;
    int maxcount = 0;
    int currcount = 0;
    while (n > 0){
        if (n % 2 == 1){
            currcount += 1;
        } else {
            currcount = 0;
        }
        if (currcount > maxcount){
            maxcount = currcount;
        }
        n = n >> 1;
    }

    cout << maxcount <<endl;

    return 0;
}