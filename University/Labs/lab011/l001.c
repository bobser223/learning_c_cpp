//
// Created by Volodymyr Avvakumov on 04.10.2024.
//
#include <stdio.h>
#include <stdlib.h>


int** create_matrix(int n, int m){
    int** matrix = (int**) calloc(n , sizeof(*matrix));
    for (int i = 0; i < n; i++){
        matrix[i] = (int*) calloc(m , sizeof(**matrix));
    }

    return matrix;
}

void delete_matrix(int** matrix, int n, int m){
    for (int i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);
}
void input(int** matrix, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("enter matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);

        }

    }

}


void print(int** matrix, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }

}

int** product(int** A, int** B, int n, int m, int k){
    int** C = create_matrix(n, k);
    for (int row_a = 0;row_a < n; row_a ++){
        for (int col_b = 0; col_b < k; col_b++ ){
            int scalar_mul = 0;
            for (int var = 0; var < m; var++){
                scalar_mul += A[row_a][var] * B[var][col_b];
            }
            C[row_a][col_b] = scalar_mul;
        }
    }
    return  C;

}

int main(){
    int n = 2, m = 3, k = 3;
//    scanf("%d", &n);
//    scanf("%d", &m);
    int* A = create_matrix(n, m);
    printf("\033[2J\033[1;1H");
    int* B = create_matrix(m, k);
    input(A, n, m);
    input(B, m, k);
//    system("clear");
    system("printf \"\\033c\"");

    printf("<================================>\n");
    print(A, n, m);
    printf("<================================>\n");
    print(B, m, k);
    printf("<================================>\n");
    int** C = product(A, B, n, m, k);
    print(C, n, k);
    delete_matrix(A, n, m);
    delete_matrix(B, m, k);
    delete_matrix(C, n, k);
    return 0;
}