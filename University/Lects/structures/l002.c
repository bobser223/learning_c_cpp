//
// Created by Volodymyr Avvakumov on 28.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Credit {
    int marks[2][2];
    float addit;} Credit;
typedef struct {
    char * name;
    float mark;
    float proj_mark[2];
    float addit;
    Credit exam; } MarkProgram;
void printMark(MarkProgram* m){ // функція від вказівника
    printf("Mark of %s:", m->name);
    printf("Gf %f %f", m->mark, (*m).proj_mark[01,m->proj_mark[1]);
    printCredit(m→exam); // 2 типи доступу до полів
}
int inputMark(MarkProgram*z){
    printf("Input Name"); // виділяємо память та ініціалізуємо!!!
    const size_t N = 20; char name(N];
    fflush(stdin); fgets(name, N, stdin);
    z->name = (char*) malloc(sizeof(name));
    strcpy(z->name, name);
    printf("Input 3 marks:");
    scanf("%f %f %f", &z->mark, &z->proj_mark[0], &z->proj_mark[1]);
    z->exam = inputCredit();
    return 0; // успішне введення
}

void printCredit(Credit c){ // функція від структури
    printf("@d %d %d %d",
           ',c.marks[0][0], c.marks[0][1],c.marks[1][0],c.marks[1][1]);
}
Credit inputCredit(){ // повертаємо структуру
    Credit c = {0,0,0,0,0.f};
    printf("Input 4 marks and additional mark");
    scanf(" %d %d %d %d", &c.marks[0][0], &c.marks[0][1], &c.marks[1][0],
          &c.marks[1][1]);
    return c;
}