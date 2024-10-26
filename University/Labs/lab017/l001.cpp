#include <iostream>
#

using namespace std;

class Person{
private:
    string _name;
    unsigned _byear;

public:
    Person(string name, unsigned byear): _name(name), _byear(byear) {};
    Person(){};

    // getters setters
    string getName() {return _name;}
    void setName(string name) {_name = name;}
    unsigned getByear() {return _byear;}
    void setByear(unsigned byear) {_name = byear;}

    // input
    void input(istream& inp = cin) {
        inp >> _name >> _byear;

    }

    void print(ostream& out = cout) const {
        out << _name << ' ' << _byear;
    }

    friend istream& operator >> (istream& inp,  Person& p) {
        p.input(inp);
        return inp;
    }

    friend ostream& operator << (ostream& out,const  Person& p) {
        p.print(out);
        return out;
    }
};


class Friend: public Person {
private:
    string _phone;

public:
    Friend(string name, unsigned byear, string phone):
    Person(name, byear), _phone(phone) {};

    string getPhone() {return _phone;}
    void setPhone(string phone){ _phone = phone;}

    void input(istream& inp = cin){
        Person::input(inp);
        inp >> _phone;
    }

    void print(ostream& out = cout){
        Person::print(out);
        out << ' ' << _phone;
    }
};


int main(){
    //    char* s;
//    gets(s);
    int result;
    asm volatile (
            "mov x0, #5\n\t"      // Завантажуємо 5 в регістр x0
            "mov x1, #10\n\t"     // Завантажуємо 10 в регістр x1
            "add %0, x0, x1\n\t"  // Додаємо x0 та x1, результат в %0
            : "=r" (result)       // Вивідний операнд
            :                      // Вхідні операнди
            : "x0", "x1"           // Збережені регістри
            );
    std::cout << "Result: " << result << std::endl;

    int i = 0;
    start_loop:
    cout << i << endl;
    i++;
    if (i > 10){
        goto end_loop;
    }
    goto start_loop;
    end_loop:
    Person p;
    p.input();




}