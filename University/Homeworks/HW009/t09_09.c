//
// Created by Volodymyr Avvakumov on 30.09.2024.
//
#include <stdlib.h>
#include <stdio.h>

void replace_rows(int*** matrix,int n,int m,int k ){
    int i = n;
    for (; i > k; i--) {
        for (int j = 0; j < m; j++) {
            (*matrix)[i][j] = (*matrix)[i - 1][j];
        }
    }
}

void add_row(int*** matrix,int n,int m, int k){
    *matrix = (int**)realloc(*matrix, sizeof(int*) * (n + 1));
    if (*matrix == NULL) {
        perror("Memory bug");
        exit(EXIT_FAILURE);
    }

    (*matrix)[n] = (int*)malloc(sizeof(int) * m);
    if ((*matrix)[n] == NULL) {
        perror("Memory bug for new row");
        exit(EXIT_FAILURE);
    }

    replace_rows(matrix, n, m, k);

    for (int j = 0; j< m; j ++){
        (*matrix)[k][j] = -1;
    }
}

void fill_matrix(int** matrix, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] = i;
        }
    }
}

void print_matrix(int** matrix, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n = 10, m = 10, k;
    int** matrix = (int**)calloc(n, sizeof(*matrix));

    for (int i = 0; i < n; i++){
        matrix[i] = (int*)calloc(m, sizeof(int));
    }

    printf("k ===");
    scanf("%d", &k);

    fill_matrix(matrix, n, m);
//    print_matrix(matrix, n, m);
    add_row(&matrix, n, m, k);
    print_matrix(matrix, n+1, m);

    for (int i = 0; i < n+1; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}