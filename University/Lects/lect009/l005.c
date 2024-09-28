//
// Created by Volodymyr Avvakumov on 28.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[] ="ABCdef";
    char str[] = {'T', 'e', 'x', 't', ' ', 'h', 'e', 'a', 'r', 'e', '\0'};
//    setlocale(LC_ALL, "Ukrainian");
    char lastname[25];
    char firstname[25];
    char fullname[51];

    strcpy(lastname, "John");

    // strcmp() // compare strings
    for(int i = 0; i < strlen(lastname); i++){
        printf("%c", lastname[i]);
    }
    return 0;
}