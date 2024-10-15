//
// Created by Volodymyr Avvakumov on 15.10.2024.
//
#include <stdio.h>
#include <string.h>

#define N 50



typedef struct Cost {
    int hryvnia;
    int kopyika;
} Cost;

typedef struct AgeLimits {
    int min_age;
    int max_age;
} AgeLimits;

typedef struct Toy {
    char name[50];
    Cost cost;
    AgeLimits age_limits;
} Toy;

typedef struct Toys_with_needed_price {
    Toy toys_with_needed_price[N];
    Cost needed_price;
    int lst_p;
} Toys_with_needed_price;

typedef struct Toys_with_needed_age_lim {
    Toy toys_with_needed_age_lim[N];
    AgeLimits needed_age_lim;
    int lst_p;
} Toys_with_needed_age_lim;

typedef struct Toys_with_needed_price_age_lim_name {
    Toy toys_with_needed_price_age_lim_name[N];
    AgeLimits needed_age_lim;
    Cost needed_price;
    int lst_p;
} Toys_with_needed_price_age_lim_name;

typedef struct Toys_with_needed_name {
    Toy toys_with_needed_name[N];
    char needed_name[50];
    int lst_p;
} Toys_with_needed_name;

void print_toy_info(Toy t);

void fill_toys_list_from_binary(Toy* toys, const char* filename, int* size) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        perror("Помилка відкриття файлу для читання");
        return;
    }
    *size = fread(toys, sizeof(Toy), N, f);
    fclose(f);
}

void write_toys_to_binary(Toy* toys, int size, const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        perror("Помилка відкриття файлу для запису");
        return;
    }
    fwrite(toys, sizeof(Toy), size, f);
    fclose(f);
}

void print_cost(Cost c) {
    printf("cost is %d.%02d UAH\n", c.hryvnia, c.kopyika);
}

void print_age_limits(AgeLimits age_limits) {
    printf("this toy age limits are %d-%d\n", age_limits.min_age, age_limits.max_age);
}

void print_toy_info(Toy t) {
    printf("%s\n", t.name);
    print_cost(t.cost);
    print_age_limits(t.age_limits);
    printf("<==========================================>\n");
}

int cost_cmp(Cost c1, Cost c2) {
    return (c1.hryvnia == c2.hryvnia && c1.kopyika == c2.kopyika);
}

int age_lim_cmp(AgeLimits al1, AgeLimits al2) {
    return (al1.max_age == al2.max_age && al1.min_age == al2.min_age);
}

Toy make_toy(char* toy_name, int uah, int kop, int min_age, int max_age){
    Toy t;
    strcpy(t.name, toy_name);
    t.cost.hryvnia = uah;
    t.cost.kopyika = kop;
    t.age_limits.min_age = min_age;
    t.age_limits.max_age = max_age;
    return t;
}

Toys_with_needed_price find_toy_with_needed_price(Toy* toys, int toys_count, Cost needed_price) {
    Toys_with_needed_price twnp;
    twnp.needed_price = needed_price;
    twnp.lst_p = 0;

    for (int i = 0; i < toys_count; i++) {
        if (cost_cmp(toys[i].cost, needed_price)) {
            twnp.toys_with_needed_price[twnp.lst_p] = toys[i];
            twnp.lst_p++;
        }
    }
    return twnp;
}

Toys_with_needed_age_lim find_toys_with_needed_age_limits(Toy* toys, int toys_count, AgeLimits needed_age_lim) {
    Toys_with_needed_age_lim twnal;
    twnal.needed_age_lim = needed_age_lim;
    twnal.lst_p = 0;

    for (int i = 0; i < toys_count; i++) {
        if (age_lim_cmp(toys[i].age_limits, needed_age_lim)) {
            twnal.toys_with_needed_age_lim[twnal.lst_p] = toys[i];
            twnal.lst_p++;
        }
    }
    return twnal;
}

void are_there_toys_with_needed_price_age_lim_name(Toy* toys, int toys_count, Cost needed_price, AgeLimits needed_age_lim, const char* needed_name, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("Помилка відкриття файлу для запису");
        return;
    }

    Toys_with_needed_price_age_lim_name result;
    result.lst_p = 0;

    for (int i = 0; i < toys_count; i++) {
        if (cost_cmp(toys[i].cost, needed_price) &&
            age_lim_cmp(toys[i].age_limits, needed_age_lim) &&
            strcmp(toys[i].name, needed_name) == 0) {
            result.toys_with_needed_price_age_lim_name[result.lst_p] = toys[i];
            result.lst_p++;
        }
    }

    if (result.lst_p == 0) {
        fprintf(f, "there are no toys with such parameters: \n");
        fprintf(f, "%s %d.%02dUAH %d-%d y.o.\n", needed_name, needed_price.hryvnia,
                needed_price.kopyika, needed_age_lim.min_age, needed_age_lim.max_age);
        printf("there are no toys with such parameters: \n");
    } else {
        fprintf(f, "there are some matches: \n");
        printf("there are some matches: \n");
        for (int i = 0; i < result.lst_p; i++) {
            fprintf(f, "%s %d.%02dUAH %d-%d y.o.\n",
                    result.toys_with_needed_price_age_lim_name[i].name,
                    result.toys_with_needed_price_age_lim_name[i].cost.hryvnia,
                    result.toys_with_needed_price_age_lim_name[i].cost.kopyika,
                    result.toys_with_needed_price_age_lim_name[i].age_limits.min_age,
                    result.toys_with_needed_price_age_lim_name[i].age_limits.max_age);
            print_toy_info(result.toys_with_needed_price_age_lim_name[i]);
        }
    }

    fclose(f);
}

int main() {
    Toy toys_0[N];
    toys_0[0] = make_toy("ball", 100, 00, 2, 13);
    toys_0[1] = make_toy("doll", 300, 00, 5, 16);
    toys_0[2] = make_toy("lego", 500, 00, 6, 99);
    toys_0[3] = make_toy("konstuctor", 100, 00, 6, 12);
    toys_0[4] = make_toy("konstuctor", 100, 00, 6, 12);
    int count = 6;

    write_toys_to_binary(toys_0, count, "Homeworks/HW011/toys.bin");

    Toy toys[N];
    int size;



    fill_toys_list_from_binary(toys, "Homeworks/HW011/toys.bin", &size);

    Cost needed_price = {100, 0};
    AgeLimits needed_age_lim = {6, 12};
    char needed_name[50] = "konstuctor";

    are_there_toys_with_needed_price_age_lim_name(toys, size, needed_price, needed_age_lim, needed_name, "Homeworks/HW011/toys_output.bin");


    return 0;
}
