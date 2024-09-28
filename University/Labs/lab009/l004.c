//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
# include <stdio.h>
#define R 25
#define C 25

void input(int matrix[][C], int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++) {
            printf("enter A[%d][%d] ", i, j);
            scanf("%i", &matrix[i][j]);
        }
        printf("\n");
    }

}

void print(int matrix[][C], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j ++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

}


int main(){
    int matrix[R][C];
    int n, m;
    printf("enter n and m: ");
    scanf("%d %d", &n, &m);
    input(matrix, n, m);
    print(matrix, n, m);

    return 0;
}

