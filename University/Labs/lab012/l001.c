//
// Created by Volodymyr Avvakumov on 07.10.2024.
//

#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
    int arr[N] = {1, 0, 9, 88, -1, 65341};
    int n = 6;
    FILE* f = fopen("Labs/lab012/file.int32", "wb");
    if (f == NULL) {
        perror("Помилка відкриття файлу");
        return 1;
    }


    fwrite(&n, sizeof(int), 1, f);
    fwrite(arr, sizeof(int), n, f);
//    f->_close
    fclose(f);

    f = fopen("Labs/lab012/file.int32", "rb");
    int m;
    while (1){
        int size = fread(&m, sizeof(int), 1, f );
        if (size == 0){
            break;
        }
//        printf("%d, ", m);

    }
    fclose(f);
    f = fopen("Labs/lab012/file.int32", "rb");
    fseek(f,0, SEEK_END);
    int size = ftell(f);
    rewind(f);//fseek(f, 0, SEEK_SET);

    n = size/sizeof(int);
    printf("%d\n", n);
    int arr2[N];
    fread(arr2, sizeof(int), n, f);
    for (int i = 0; i < n; i++){
//        printf("%d ", i);
        printf("%d ", arr2[i]);
    }

    return 0;
}