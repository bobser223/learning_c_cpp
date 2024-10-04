//
// Created by Volodymyr Avvakumov on 04.10.2024.
//
#include <iostream>
#include <cstdio>
#include <string>
#include<cstdlib>
using namespace std;

// if no typedef -> struct Struct a;
typedef struct Struct{
    int n;
    char s[25];
    Struct* next;

} Struct;
int main(){
//    system("Color 70");
//    Struct a;
//    a.n = 25;
//    strcpy(a.s, "Hello!");
    Struct b = {.n = 10, "Hello!"};
    Struct* a = (Struct*) malloc(sizeof(*a));
    (*a).n = 10;
    strcpy((*a).s, "Hello!");
    // posible
    strcpy(a->s, "Hello!");
    a ->next = a;
//    printf("\033[0;36m %d %s\n", a.n, a.s);
    printf("\033[0;36m %p %p\n", a, a-> next);
    printf("\033[0;36m %d %s\n", (*a).n, (*a).s);
    printf("\033[0;36m %d %s\n", a->n, a->s);
    printf(" size: %d\n", sizeof(Struct));
    printf("\033[0;34m %d %s\n", b.n, b.s);
    return 0;
}