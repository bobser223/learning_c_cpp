//
// Created by Volodymyr Avvakumov on 08.10.2024.
// je

#include <stdio.h>
#include <string.h>

#define N 50

typedef struct Cost{
    int hryvnia;
    int kopyika;

} Cost;

typedef struct AgeLimits{
    int min_age;
    int max_age;
} AgeLimits;

typedef struct Toy{
    char name[50];
    Cost cost;
    AgeLimits age_limits;
} Toy;

typedef struct Toys_with_needed_price{
    Toy toys_with_needed_price[N];
    Cost needed_price;
    int lst_p;
} Toys_with_needed_price;

typedef struct Toys_with_needed_age_lim{
    Toy toys_with_needed_age_lim[N];
    AgeLimits needed_age_lim;
    int lst_p;
} Toys_with_needed_age_lim;

typedef struct Toys_with_needed_price_age_lim_name{
    Toy toys_with_needed_price_age_lim_name[N];
    AgeLimits needed_age_lim;
    Cost needed_price;

    int lst_p;
}Toys_with_needed_price_age_lim_name;

typedef struct Toys_with_needed_name{
    Toy toys_with_needed_name[N];
    char needed_name[50];
    int lst_p;
}Toys_with_needed_name;

void fill_toys_list(Toy* toys, char* filename, int* size){
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        perror("Помилка відкриття файлу");
    }
    int i = 0;
    while (fscanf(f, "%s %d.%dUAH %d-%d y.o.",
                  toys[i].name,
                  &toys[i].cost.hryvnia,
                  &toys[i].cost.kopyika,
                  &toys[i].age_limits.min_age,
                  &toys[i].age_limits.max_age) == 5) {
        i++;
    }
    *size = i;
    fclose(f);
}

void print_cost(Cost c){
    printf("cost is %d.%02d UAH\n", c.hryvnia, c.kopyika);
}

void print_age_limits(AgeLimits age_limits){
    printf("this toy age limits are %d-%d\n", age_limits.min_age, age_limits.max_age);
}

void print_toy_info(Toy t){
    printf("%s\n", t.name);
    print_cost(t.cost);
    print_age_limits(t.age_limits);
    printf("<==========================================>\n");
}

void print_all_toys(Toy* toys,int size){
    for (int i = 0; i < size; i++){
        print_toy_info(toys[i]);
    }

}

int cost_cmp(Cost c1, Cost c2){
    if (c1.hryvnia == c2.hryvnia && c1.kopyika == c2.kopyika)
        return 1;
    return 0;
}

int age_lim_cmp(AgeLimits al1, AgeLimits al2){
    if(al1.max_age == al2.max_age && al1.min_age == al2.min_age)
        return 1;
    return 0;
}

Cost input_value(){
    Cost c;
    printf("enter hryvnias: ");
    scanf("%d", &c.hryvnia);
    printf("enter kopyikas: ");
    scanf("%d", &c.kopyika);
    return c;
}

AgeLimits copy_age_limits(AgeLimits al){
    AgeLimits al_result;
    al_result.min_age = al.min_age;
    al_result.max_age = al.max_age;
    return al_result;
}

Toys_with_needed_price find_toy_with_needed_price(Toy* toys, int toys_count, Cost needed_price){
    Toys_with_needed_price twnp;
    twnp.needed_price = needed_price;
    twnp.lst_p = 0;

    for (int i = 0; i < toys_count; i++ ){
        if (cost_cmp(toys[i].cost, needed_price)){
            twnp.toys_with_needed_price[twnp.lst_p] = toys[i];
            twnp.lst_p ++;
        }
    }
    return twnp;
}

Toys_with_needed_age_lim find_toys_with_needed_age_limits(Toy* toys, int toys_cunt, AgeLimits needed_age_lim){
    Toys_with_needed_age_lim twnal;
    twnal.needed_age_lim = copy_age_limits(needed_age_lim);
    twnal.lst_p = 0;
    for (int i = 0; i < toys_cunt; i++){
        if (age_lim_cmp(toys[i].age_limits, needed_age_lim)) {
            twnal.toys_with_needed_age_lim[twnal.lst_p] = toys[i];
            twnal.lst_p ++;
        }
    }
    return  twnal;
}

Toys_with_needed_name find_toys_with_needed_name(Toy* toys, int toys_cunt, char* needed_name){
    Toys_with_needed_name twnm;
    strcpy(twnm.needed_name, needed_name);
    twnm.lst_p = 0;
    for (int i = 0; i < toys_cunt; i++){
        if ((strcmp(toys[i].name, needed_name)) == 0) {
            twnm.toys_with_needed_name[twnm.lst_p] = toys[i];
            twnm.lst_p ++;
        }
    }
    return  twnm;
}

Toys_with_needed_price_age_lim_name find_toys_with_needed_price_age_lim_name(Toy* toys, int toys_count, Cost needed_price, AgeLimits needed_age_lim, char* needed_name){
    Toys_with_needed_price_age_lim_name result;
    Toys_with_needed_name twnd = find_toys_with_needed_name(toys, toys_count, needed_name);
//    printf("%d\n", twnd.lst_p);
    Toys_with_needed_price twnp = find_toy_with_needed_price(twnd.toys_with_needed_name, twnd.lst_p, needed_price);
//    printf("%d\n", twnp.lst_p);
    Toys_with_needed_age_lim twnagl = find_toys_with_needed_age_limits(twnp.toys_with_needed_price, twnp.lst_p, needed_age_lim);
//    printf("%d\n", twnagl.lst_p);

    for (int i = 0; i < twnagl.lst_p; i++) {
        result.toys_with_needed_price_age_lim_name[i] = twnagl.toys_with_needed_age_lim[i];
    }

    result.lst_p = twnagl.lst_p;
    return result;
}

void are_there_toys_with_needed_price_age_lim_name(Toy* toys, int toys_count, Cost needed_price, AgeLimits needed_age_lim, char* needed_name, char* filename){
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("Помилка відкриття файлу для запису");
        return;
    }

    Toys_with_needed_price_age_lim_name result = find_toys_with_needed_price_age_lim_name(toys, toys_count, needed_price, needed_age_lim, needed_name);
    if (result.lst_p == 0){
            fprintf(f, "there are no toys with such parameters: \n");
        fprintf(f, "%s %d.%02dUAH %d-%d y.o.\n",needed_name, needed_price.hryvnia,
                needed_price.kopyika,
                needed_age_lim.min_age,
                needed_age_lim.max_age);
        printf("there are no toys with such parameters: \n");
        printf( "%s %d.%02dUAH %d-%d y.o.\n",needed_name, needed_price.hryvnia,
                needed_price.kopyika,
                needed_age_lim.min_age,
                needed_age_lim.max_age);
    } else {
        fprintf(f, "there are some matches: \n");
        printf("there are some matches: \n");
        for (int i = 0; i < result.lst_p; i++){
            fprintf(f, "%s %d.%02dUAH %d-%d y.o.\n",
                    result.toys_with_needed_price_age_lim_name[i].name,
                    result.toys_with_needed_price_age_lim_name[i].cost.hryvnia,
                    result.toys_with_needed_price_age_lim_name[i].cost.kopyika,
                    result.toys_with_needed_price_age_lim_name[i].age_limits.min_age,
                    result.toys_with_needed_price_age_lim_name[i].age_limits.max_age);
            print_toy_info(result.toys_with_needed_price_age_lim_name[i]);
        }
    }


}


int main(){
    Toy toys[N];
    int size;
    fill_toys_list(toys, "Homeworks/HW011/toys.txt", &size);
//    printf("%d\n", size);
//    print_all_toys(toys, size);

    Cost needed_price;
//    needed_price = input_value();

    needed_price.hryvnia = 100;
    needed_price.kopyika = 00;

    AgeLimits needed_age_lim;

//    printf("enter min age(max ege == 12): ");
//    scanf("%d", &(needed_age_lim.min_age));
    needed_age_lim.min_age = 6;
    needed_age_lim.max_age = 12;


    char needed_name[50];
//    printf("enter needed toy name");
//    scanf("%s", needed_name);

//    strcpy(needed_name, "konstucto");
    strcpy(needed_name, "konstuctor");

    are_there_toys_with_needed_price_age_lim_name(toys, size, needed_price, needed_age_lim, needed_name, "Homeworks/HW011/toys_output.txt");

}