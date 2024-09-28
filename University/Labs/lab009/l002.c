//
// Created by Volodymyr Avvakumov on 27.09.2024.
//
# include <stdio.h>
#define R  3
#define C 3

void change(int matrix[][C],int r, int c, int n, int m){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j ++) {
            if (matrix[i] [j] == m){
                matrix[i] [j] = n;
            }
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
    int matrix[R][C] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}

    };
    int n, m;
    printf("enter n: ");
    scanf("%d", &n);
    printf("enter m: ");
    scanf("%d", &m);

    change(matrix, R, C, n, m);
    print(matrix, R, C);

    return 0;
}

