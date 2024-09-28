//
// Created by Volodymyr Avvakumov on 28.09.2024.
//

#include <stdio.h>
//#include <stdlib.h>

#define N 50
#define M 50


typedef double matrix_var ; // if you'll change it, don't forget to change arguments in scanf() and printf() also

void input(matrix_var matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("enter A[%d][%d] ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
        printf("\n");
    }
}


void print(matrix_var matrix[][M], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }

}

void matrix_mull(matrix_var matrix1[][M],int n, int m, matrix_var matrix2[][M], int k, matrix_var matrixResult[][M]){

    for (int row_m1 = 0; row_m1 < n; row_m1++){
        for(int col_m2 = 0; col_m2 < k; col_m2++){
            matrix_var scalar_mull = 0;
            for (int var = 0; var < m; var++){
                scalar_mull += matrix1[row_m1][var] * matrix2[var][col_m2];
//                printf("%lf\n", scalar_mull);
            }
//            printf("%lf\n", matrixResult[col_m2][row_m1]);
            matrixResult[row_m1][col_m2] = scalar_mull;
//            print(matrixResult, m, m);

        }

    }
//    print(matrixResult, m, m);




}


int main(){
//    matrix_var matrix1[N][M] = {
//            {1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {11, 12, 13, 14}
//
//    };
//
//    matrix_var matrix2[N][M] = {
//            {1, 2, 3, 4, 5},
//            {12, 25, 16, 17, 7},
//            {100, 29, 71, 1, 43},
//            {66, 64, 9, -1, 77}
//    };
//
//    int n = 3, m = 4, k = 5;
    matrix_var matrix1[N][M];

    matrix_var matrix2[N][M];

    int n, m, k;
    printf("enter the size of the first matrix: n (number of rows) = ");
    scanf("%d", &n);
//    system("clear");

    printf("m (number of columns) = ");
    scanf("%d", &m);
    printf("enter the size of the second matrix: k (it's number of columns, the number of rows == m) = ");
    scanf("%d", &k);
    matrix_var matrixResult[N][M];
    printf("now it's tome to enter the first matrix ----->\n");
    input(matrix1, n, m);
    printf("wow, and the second one ----->\n");
//    print(matrix1, n, m);
    input(matrix2, m, k);
//    print(matrix2, m, k);
    matrix_mull(matrix1, n, m, matrix2, k, matrixResult);
    print(matrixResult, n, k);




}