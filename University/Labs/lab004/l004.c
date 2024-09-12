//
// Created by Volodymyr Avvakumov on 09.09.2024.
//
#include <math.h>
#include <stdio.h>
#include <stdint.h>
uint16_t mul(uint8_t a, uint8_t b){
    return ((uint16_t)a * (uint16_t)b);
}

int main(){
    uint8_t x, y;

    scanf("%hhu %hhu", &x, &y);
    printf("%hu", mul(x, y));

    return 0;
}