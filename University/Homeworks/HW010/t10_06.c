//
// Created by Volodymyr Avvakumov on 07.10.2024.
// a
#include <stdio.h>

typedef struct Cost{
    int hryvnia;
    int kopyika;

} Cost;

Cost input_value(){
    Cost c;
    printf("enter hryvnias: ");
    scanf("%d", &c.hryvnia);
    printf("enter kopyikas: ");
    scanf("%d", &c.kopyika);
    return c;
}

void print_cost(Cost c){
    printf("cost is %d.%02d UAH", c.hryvnia, c.kopyika);

}

int main(){
    Cost c = input_value();
    print_cost(c);

    return 0;
}
