//
// Created by Volodymyr Avvakumov on 01.11.2024.
//
#include <string>
#include <iostream>

using namespace std;

class Human{
protected:
    std::string name;
public:
    Human(string name): name(name) {
        cout << "creating human " << name << endl;
    }
    virtual ~Human(){
        cout << "Deleting human " << name << endl;
    }
    virtual void print(){
        cout << name;
    }
    void hello() {cout << "Hello from "; print(); cout << endl;}

};


class Student:virtual public Human{
protected:
    int course;
    string univ;
public:
    Student(string name, int course, string univ): Human(name), course(course), univ(univ){
        cout << "creating student " << name << endl;
    };
    virtual ~Student() override { cout << "Deleting student " << name << endl;}

    virtual void print() override {Human::print(); cout << ' ' << univ << ' ' << course;}
};

class Teacher:virtual  public Human{
protected:
    double salary;
    string univ;
public:
    Teacher(string name, double salary, string univ): Human(name), salary(salary), univ(univ){
        cout << "creating teacher " << name << endl;
    };
    virtual ~Teacher() override { cout << "Deleting teacher " << name << endl;}

    virtual void print() override {Human::print(); cout << ' ' << univ << ' ' << salary;}
};

class PGS: public Student, public Teacher{
public:
    PGS(string name, int course, double salary, string univ):Human(name), Student(name, course, univ), Teacher(name, salary, univ){
        cout << "Creating PGS" << name << endl;
    };
    virtual ~PGS() override {cout << "Deleting PGS " << Student::name << endl; }

    virtual void print() override{
        Teacher::print(); cout << ' ' << course;
    }
    void hui(){
        cout << Teacher::univ << endl;
    }

};

int main(){
//    Human h("Bobser");
//    Human* h = new Human("Bobser");
//    h -> hello();
    const int N = 4;
    Human* arr[N] = {
            new Human("Bobser"),
            new Student("Shaitan",2, "KNU"),
            new Teacher("Oliintk", 25657.43, "KNU"),
            new PGS("Dmytro", 1,-100000, "KNU")
    };
    for(int i = 0; i < N; i++){
        arr[i] ->hello();
    }

    for (int i = 0; i < N; i++){
        delete arr[i];
    }

//    delete h;
    return 0;
}