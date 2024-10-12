
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <python.h>
#define N 100


typedef struct {
    double coef;
    int deg;
} Monom;


typedef struct {
    int m;
    Monom monoms[N];
} Poly;


Poly create_poly(double* a, int m) {
    Poly p;
    p.m = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] != 0) {
            Monom monom = {.coef = a[i], .deg = i};
            p.monoms[p.m++] = monom;
        }
    }
    return p;
}


void print_poly(Poly p) {
    int i = 0;
    for (; i < p.m - 1; i++) {
        printf("%gx^%ld + ", p.monoms[i].coef, p.monoms[i].deg);
    }
    printf("%gx^%ld\n", p.monoms[i].coef, p.monoms[i].deg);
}


void print_polynoms(Poly* ps, int n) {
    for (int i = 0; i < n; i++) {
        print_poly(ps[i]);
    }
}


void write_polynoms(Poly* ps, int n, char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    fwrite(&n, sizeof (n), 1, f);
    for (int i = 0; i < n; i++) {
        fwrite(&ps[i].m, sizeof (int), 1, f);
        fwrite(ps[i].monoms, sizeof (Monom), ps[i].m, f);
    }
    fclose(f);
}


int read_polynoms(Poly* ps, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    int n;
    fread(&n, sizeof (n), 1, f);
    for (int i = 0; i < n; i++) {
        fread(&ps[i].m, sizeof (int), 1, f);
        fread(ps[i].monoms, sizeof (Monom), ps[i].m, f);
    }
    fclose(f);
    return n;
}


Poly read_poly(int k, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    int n, m;
    fread(&n, sizeof (n), 1, f);
    if (k >= n) exit(1);

    for (int i = 0; i < k; i++) {
        fread(&m, sizeof (int), 1, f);
        fseek(f, m * sizeof (Monom), SEEK_CUR);
    }
    Poly p;
    fread(&p.m, sizeof (int), 1, f);
    fread(p.monoms, sizeof (Monom), p.m, f);

    fclose(f);
    return p;
}


void append_poly(Poly p, char* filename) {
    FILE* f = fopen(filename, "rb+");
    if (!f) exit(1);

    int n;
    fread(&n, sizeof (n), 1, f);
    n++;
    rewind(f);
    fwrite(&n, sizeof (n), 1, f);

    fseek(f, 0, SEEK_END);
    fwrite(&p.m, sizeof (int), 1, f);
    fwrite(p.monoms, sizeof (Monom), p.m, f);

    fclose(f);
}


int main() {
    char F[N] = "F.poly";
    int n = 4;
    int m = 7;
    double arr[N][N] = {
            {1.0, 2.1, 0.1, 3.1, -1.0, 0.0, -0.1},
            {0.0, -9.2, 0.1, 0.0, 3.6, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
            {0.0, 6.0, 1.0, 0.0, 0.0, 0.0, 0.0}
    };
    Poly polynoms_1[N];
    for (int i = 0; i < n; i++) {
        polynoms_1[i] = create_poly(arr[i], m);
    }
    write_polynoms(polynoms_1, n - 1, F);
    append_poly(polynoms_1[3], F);

    Poly polynoms_2[N];
    n = read_polynoms(polynoms_2, F);
    print_polynoms(polynoms_2, n);
    printf("\n");

    Poly p = read_poly(3, F);
    print_poly(p);

    return 0;
}
