//
// Created by Volodymyr Avvakumov on 09.09.2024.
//

#include <stdint.h>
#include <stdio.h>
#include <limits.h>

uint32_t sum(uint32_t a, uint32_t b, bool* overflow){
    if (a > INT_MAX - b){
        (*overflow) = true;
    } else {
        (*overflow) = false;
    }
    return a + b;
}

int main() {
    uint32_t x, y, z;
    scanf("%li %li", &x, &y);
    bool overflow;
    z = sum(x, y, &overflow);
    if (overflow){
        printf("overflow");
    } else {
        printf("all wright");
    }

}