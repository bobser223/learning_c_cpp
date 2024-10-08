//
// Created by Volodymyr Avvakumov on 07.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define F "Labs/lab012/input.int32"
#define G "Labs/lab012/output.int32"


void input_until_zero(const char* filename){
    FILE* f = fopen(filename, "wb");
    if (!f){
        exit(1);
    }

    while (1) {
        int m;
        scanf("%d", &m);
        if (m ==0)
            break;
        fwrite(&m, sizeof(m), 1, f);
    }
    fclose(f);
}

void print(const char* filename){
    FILE* f = fopen(filename, "rb");
    if (!f){
        exit(1);
    }
    int n;
    fseek(f,0, SEEK_END);
    int size = ftell(f);
    rewind(f);//fseek(f, 0, SEEK_SET);

    n = size/sizeof(int);

    int arr[N];

    fread(arr, sizeof(int), n, f);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    fclose(f);
}

void read_file(const char* filename, int* arr){

    FILE* f = fopen(filename, "rb");
    if (!f){
        exit(1);
    }
    int n;
    fseek(f,0, SEEK_END);
    int size = ftell(f);
    rewind(f);//fseek(f, 0, SEEK_SET);

    n = size/sizeof(int);


    fread(arr, sizeof(int), n, f);

    fclose(f);
}

//void write_odd_to_file(const char* filename_input,const char* filename_output){
//    int* arr[N];
//    read_file(filename_input, arr);
//    for (int i = 0; );
//
//}

void a(const char* input,const char* output){
    FILE* finp = fopen(input, "rb");
    if(!finp) exit(1);
    FILE* fout = fopen(output, "wb");
    if(!fout) exit(1);
    while(!feof(finp)){
        int m;
        int size;
        size = fread(&m, sizeof(int), 1, finp);
        if (feof(finp)){
            break;
        }
        if (m % 2 == 0)
            fwrite(&m, sizeof(int), 1, fout);
    }
    fclose(finp);
    fclose(fout);

}

int main(){
    input_until_zero(F);
    print(F);
    int* arr[N];
    a(F, G);
    printf("<++++++++++++++++++++++++++++++++++++>\n");
    print(G);

}