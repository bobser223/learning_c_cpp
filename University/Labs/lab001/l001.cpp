//
// Created by Volodymyr Avvakumov on 02.09.2024.
//
#include <stdio.h>

int main(){
    char c = 'a';
    printf("%c %i bytes %li \n", c, c, sizeof(c));

    printf("hello, world! \n");
    long int y = 0;
    printf("%i", y);
    printf("%i bytes %i \n ", y, sizeof(y));
    short int x = 15;
    printf("%i", x);
    printf("%i bytes %i \n ", x, sizeof(x));
    long long int z = 14;
    printf("%i", z);
    printf("%i bytes %i \n ", z, sizeof(z));


    float f = 1.233424;
    printf("%f bytes %i \n ", f, sizeof(f));
    double d = 2.423543;
    printf("%lf bytes %i \n ", d, sizeof(d));
    long double ld = 123.435464;
    printf("%Lf bytes %i \n ", ld, sizeof(ld));
    return 0;
}