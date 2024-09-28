//
// Created by Volodymyr Avvakumov on 26.09.2024.
//
#include <stdlib.h>
#include <stdio.h>

int main(){

    void* malloc(size_t size);
    int *p1 = malloc(4*sizeof(int));
    int *p3 = calloc(4, sizeof(*p3));
    if(p1){
        printf("jiowej");
    }
    else{
        printf("mmmmm");
    }
    free(void * p3);
    return 0;
}