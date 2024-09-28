//
// Created by Volodymyr Avvakumov on 28.09.2024.
//
#include <stdio.h>
#define MAX 10
int main(){
// Stack
        int x; // 0x1441000, 0x14110000 +4
        char y; // 0x1441000 + 4, 0x14110000 +5
        double z; // 8X110089 + 5, 0X110000 + 13

        char mas[3]; // 0x1111000D, 0x1111000D + 3
        int mas2[MAX]; // 0x11110010, 0x11110010 + 10*4

        int* p1; // 0x11110010 + 10*4, + 0x11110010 + 10*4 + 4(for 32bit arch) sizeof(p1) == sizeof (char*)
        char* p2; // // 0x11110010 + 10*4 + 4, + 0x11110010 + 10*4 + 8(for 32bit arch)
        p1 = &x; // ok, p1== 0x1/1110000, *p1 = x
        p2 = &mas2; // ok, p2== 0x1111000D, *p2 = mas [®]
        p2++;
        p1 = &mas2[0]; // p1 = mas2;
        p1 = &mas[0]; // not exactly ok
        p1 = (int*) (&mas[]); // maybe ok, but suspicious
        void* p; // 0x11110010 + 10*4 + 12, 0x11110010 + 10*4 + 16
        p = &mas2;
        p = &mas;
}