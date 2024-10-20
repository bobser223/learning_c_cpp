//
// Created by Volodymyr Avvakumov on 18.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Student{
    string surname;
    int cource;
    int group;
    vector<int> marks;
};

void make_students_file(char* filename){
    Student s1("Bobser", 1, 2, {1, 23 , 5});
    Student s2("Bobser", 1, 2, {1, 26 , 5});
    fstream f;
    f.open(filename, f.out);
    cout << s1.surname << s1.cource << s1.group <<
}


int main(){

}