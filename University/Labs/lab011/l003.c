//
// Created by Volodymyr Avvakumov on 04.10.2024.
//
#include <stdio.h>

typedef struct Date {
    int day, month, year;
} Date;


Date input(){
    Date date;
    scanf("%d.%d.%d", &date.day, &date.month, &date.year);
    return date;
}

void print_date(Date date){
    printf("%02d.%02d.%d", date.day, date.month, date.year);
}

int main(){
    Date d = input();
    print_date(d);

}