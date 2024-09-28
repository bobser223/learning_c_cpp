//
// Created by Volodymyr Avvakumov on 28.09.2024.
//#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    n = 20;
    int* mas3 = malloc(n * sizeof(int));

    if (mas3){
        mas3[0] = 1;
        mas3[2] = 2;

        free(mas3);
    } else{
        printf("biba boba");
    }
    // free(mas3); // problem
    int* mas4 = calloc(n, sizeof(*mas4)); // allocate memory on Heap kucha
    printf("%d", mas4[0]);
    free(mas4);



}