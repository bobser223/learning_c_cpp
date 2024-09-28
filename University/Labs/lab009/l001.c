//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
#include <stdio.h>

#define N 3
#define M 5

void print(int matrix[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}
void print2(int matrix[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

}

void print_ptr(int matrix[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("%p ", &matrix[i][j]);
        }
        printf("\n");
    }

}

void input(int matrix[][M], int n, int m){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j ++) {
                scanf("%i ", &matrix[i][j]);
            }
            printf("\n");
        }

}

int main(){
    int matrix[N][M] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 20},
            {1, 2, 3, 4, 5}

    };
    input(matrix, N, M);
    print(matrix, N, M);
//    print_ptr(matrix, N, M);
//    printf("%p\n", matrix);
//    printf("%p\n", matrix + 1);
//    printf("%d\n", **(matrix));
//    printf("%d\n", *(*(matrix + 1)));

    print2(matrix, N, M);

    return 0;
}