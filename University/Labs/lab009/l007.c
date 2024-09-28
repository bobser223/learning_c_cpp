//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
#include <stdio.h>
#include <math.h>
#define N 3
#define M 3

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
void getMatrixWithoutRowAndColumn(int **matrix, int n, int m, int rowToRemove, int colToRemove, int **result) {
    int r = 0; // Row index for result matrix
    for (int i = 0; i < n; i++) {
        if (i == rowToRemove)
            continue; // Skip the row to remove
        int c = 0; // Column index for result matrix
        for (int j = 0; j < m; j++) {
            if (j == colToRemove)
                continue; // Skip the column to remove
            result[r][c] = matrix[i][j];
            c++;
        }
        r++;
    }
}

double det(int matrix[][M], int n, int m, int sigma){
    int size = sizeof(matrix) / sizeof(matrix[0]);
    if (size == 2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    for (int j = 0; j < m; j++){
        int newM[n-1][m -1];
        int r = 0; // Row index for result matrix
        for (int i = 0; i < n; i++) {
            if (i == 0)
                continue; // Skip the row to remove
            int c = 0; // Column index for result matrix
            for (int j_ = 0; j < m; j++) {
                if (j_ == j)
                    continue; // Skip the column to remove
                newM[r][c] = matrix[i][j_];
                c++;
            }
            r++;
        }
//        getMatrixWithoutRowAndColumn(matrix, n, m, 0, j, newM);
        return det(newM, n-1, m-1, sigma*pow(-1, j));
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
            {6, 7, 5},
            {0, 1, 3},
            {4, 5, 1 }

    };
    int newM[N-1][M -1];

    printf("%lf", det(matrix, N, M, 1));

    return 0;
}