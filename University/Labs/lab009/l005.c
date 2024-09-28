//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
#include <stdio.h>

#define N 4
#define M 4

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

void trans(int matrix[][M], int matrixT[][N], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            matrixT[j][i] = matrix[i][j];
        }
    }

}




int main(){
    int matrix[N][M] = {
            {1, 2, 3, 4},
            {6, 7, 8, 9},
            {1, 2, 3, 4},
            {4, 6, 7, 2}
    };
    int matrixT[M][N];
    print(matrix, N, M);

    trans(matrix, matrixT, N, M);
//    print(matrixT, M, N);
    printf("++++++++++++++++++++++++++++++++++\n");
    print(matrixT, M, N);
    printf("++++++++++++++++++++++++++++++++++\n");

    return 0;
}