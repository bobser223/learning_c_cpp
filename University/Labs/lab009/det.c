//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
#include <stdio.h>
#include <math.h>
#define N 4
#define M 4

void print(int matrix[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
}


void minor(int matrix[][M], int matrix_size, int newMatrix[][M], int newM_size, int rowToRemove,  int colToRemove){

    int r = 0; // Row index for result matrix
    for (int i = 0; i < matrix_size; i++) {
        if (i == rowToRemove)
            continue; // Skip the row to remove
        int c = 0; // Column index for result matrix
        for (int j = 0; j < matrix_size; j++) {
            if (j == colToRemove)
                continue; // Skip the column to remove
            newMatrix[r][c] = matrix[i][j];
            c++;
        }
        r++;
    }
}

double det(int matrix[][M], int matrix_size){
    if (matrix_size == 1) {
        return matrix[0][0];
    }
    if (matrix_size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    int rowToRemove = 0;
    double d = 0;
    for (int colToRemove = 0; colToRemove < matrix_size; colToRemove++){
        int newMatrix[N][M];
        int newM_size = matrix_size - 1;
        minor(matrix, matrix_size, newMatrix, newM_size, rowToRemove, colToRemove);
        d += (pow(-1, (colToRemove + 2))) * matrix[rowToRemove][colToRemove]*det(newMatrix, newM_size);

        print(newMatrix, newM_size, newM_size);



    }
    return d;
}



int main(){
    int matrix[N][M] = {
            {6, 7, 5, 8},
            {0, 1, 3, 0},
            {4, 5, 1, 9},
            {1, 7, 11, 23}

    };

    printf("%lf", det(matrix, N));

    return 0;
}