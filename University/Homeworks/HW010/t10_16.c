//
// Created by Volodymyr Avvakumov on 07.10.2024.
//a v
#include <stdio.h>
#include <string.h>

#define N 3


typedef struct Student{
    char surname[50];
    int group_number;
    int marks[3];
} Student;

typedef struct Students_with_debt{
    Student students_with_debt[N];
    int lst_p;
} Students_with_debt;

typedef struct Students_with_better_mark_then_alpha{
    Student students_with_better_mark_then_alpha[N];
    int lst_p;
    double alpha;
} Students_with_better_mark_then_alpha;

Student input_student(){
    Student s;
    printf("enter surname: ");
    scanf("%49s", s.surname);
    printf("enter number of his group: ");
    scanf("%d", &(s.group_number));
    for (int i = 0; i < 3; i++){
        printf("enter %d mark: ", i+1);
        scanf("%d",&(s.marks[i]));

    }
    return s;

}

void print_student(Student s){
    printf("Hi, my surname is %s, i'm from %d group.\n", s.surname, s.group_number);
    printf("my marks table is: \n");
    printf("+--------+----------\n");

    for (int i = 0; i<3; i++) {
        printf("| mark %d | %d |\n", i + 1, s.marks[i]);
    }

}

void print_students_list(Student* lst, int size,const char* comment){
    if (comment == NULL) {
        comment = "Students list:";
    }
    printf("%s\n", comment);

    for (int i = 0; i< size; i++){
        print_student(lst[i]);
    }
}

void make_students_list(Student* lst){
    for (int i = 0; i < N; i++){
        lst[i] = input_student();
    }
}

int student_has_dept(Student s){
    for(int i = 0; i < 3; i++){
        if (s.marks[i] == 0){
            return 1;
        }
    }
    return 0;
}

Students_with_debt find_students_with_debt(Student* students){
//    Student students_with_debt[N];

    Students_with_debt s_w_d;
    s_w_d.lst_p = 0;

    int lst_p;
    for (int i =0; i< N; i++){
        if (student_has_dept(students[i])) {
            s_w_d.students_with_debt[s_w_d.lst_p] = students[i];
            s_w_d.lst_p++;
        }
    }
    return s_w_d;
}

int minimum(const double* arr, int size){
    double min = arr[0];
    int min_i = 0;
    for (int i = 1; i < size; i++){
        double var = arr[i];
        if (var < min){
            min = var;
            min_i = i;
        }
    }
    return min_i + 1;
}

int hardest_subject(Student* students){
    int subject_number = 0;
    double average_marks[] = {students[0].marks[0], students[0].marks[1], students[0].marks[2]};
    for (int i = 1; i < N; i++){
        for (int j = 0; j < 3; j ++){
            average_marks[j] += students[i].marks[j];
        }

    }
    for (int i = 0; i < 3; i++){
        average_marks[i] /= N;
    }
    subject_number = minimum(average_marks, 3);
    return subject_number;
}

int all_marks_better_then_alpha(Student s, double alpha){
    for (int i = 0; i < 3; i++){
        if (s.marks[i] <= alpha){
            return 0;
        }
    }
    return 1;
}

Students_with_better_mark_then_alpha find_students_with_better_mark_then_alpha(Student* students, double alpha){
    Students_with_better_mark_then_alpha s_b;
    s_b.lst_p = 0;
    s_b.alpha = alpha;
    for (int i = 0; i<N; i++){
        if (all_marks_better_then_alpha(students[i], alpha)){
            s_b.students_with_better_mark_then_alpha[s_b.lst_p] = students[i];
            s_b.lst_p ++;
        }
    }
    return s_b;
}



int main(){
    Student a;
    strcpy(a.surname, "A");
    a.group_number = 1;
    a.marks[0] = 1;
    a.marks[1] = 2;
    a.marks[2] = 3;

    Student b;
    strcpy(b.surname, "B");
    b.group_number = 2;
    b.marks[0] = 4;
    b.marks[1] = 0;
    b.marks[2] = 6;

    Student c;
    strcpy(c.surname, "C");
    c.group_number = 3;
    c.marks[0] = 7;
    c.marks[1] = 8;
    c.marks[2] = 9;

    Student students[N] = {a, b, c};
//    Student students[N];
//    make_students_list(students);
    int alpha = 6;
    print_students_list(students, N, NULL);

    Students_with_debt s_w_d = find_students_with_debt(students);
    print_students_list(s_w_d.students_with_debt, s_w_d.lst_p, "Students with dept:");

    Students_with_better_mark_then_alpha s_d = find_students_with_better_mark_then_alpha(students, alpha);
    print_students_list(s_d.students_with_better_mark_then_alpha, s_d.lst_p, "students with better mark than alpha: ");


    printf("the hardest subject is %d \n", hardest_subject(students));



    return 0;
}
