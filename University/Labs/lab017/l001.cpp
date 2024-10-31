#include <iostream>
#include <fstream>

using namespace std;

class Person{
private:
    string _name;
    unsigned _byear;

public:
    Person(string name, unsigned byear): _name(name), _byear(byear) {};
    Person(){};
//    virtual ~Person() {cout << "person dead" << endl;}

    // getters setters
    string getName() {return _name;}
    void setName(string name) {_name = name;}
    unsigned getByear() {return _byear;}
    void setByear(unsigned byear) {_name = byear;}

    // input
    virtual void input(istream& inp = cin) {
        inp >> _name >> _byear;

    }

     virtual void print(ostream& out = cout) const {
        out << _name << ' ' << _byear;
    }

    friend istream& operator >> (istream& inp,  Person& p) {
        p.input(inp);
        return inp;
    }

    friend ostream& operator << (ostream& out,const Person& p) {
        p.print(out);
        return out;
    }
};


class Friend: public Person {
private:
    string _phone;

public:
    Friend(string name = "", unsigned byear = 20000, string phone = "56788788622"):
    Person(name, byear), _phone(phone) {};
//    virtual ~Friend() {cout << "friend dead" << endl;}

    string getPhone() {return _phone;}
    void setPhone(string phone){ _phone = phone;}

    void input(istream& inp = cin) override{
        Person::input(inp);
        inp >> _phone;
    }

     virtual void print(ostream& out = cout) const override {
        Person::print(out);
        out << ' ' << _phone;
    }
};

class PhoneBook {
private:
    Friend* book;
    int count;
public:

    PhoneBook(){
        book = new Friend[100];
    };
    ~PhoneBook(){
        delete[] book;
    }
    void read(const char* filename){
        ifstream f(filename);
        if(!f.is_open())
            throw logic_error("Cannot find file");
        count = 0;
        while(f.good()){
            f >> book[count++];
            if(f.fail()) break;

        }
        f.close();

    }

    string search(const string& name){
        for (int i = 0; i < count; i++){
            if (book[i].getName() == name){
                return book[i].getPhone();
            }
        }
        cout << "no friend" << endl;
    }

    void write(const char* filename){
        ofstream f(filename);
        if(!f.is_open())
            throw logic_error("Cannot open file");
        for (int i = 0; i < count; i++){
            f << book[i] << endl;
        }
        f.close();
    }

    void append(Friend f){
        book[count++] = f;
    }

    friend ostream& operator << (ostream& out,const PhoneBook& pd) {
        for (int i = 0; i < pd.count; i++){
            out << pd.book[i] << endl;
        }
        return out;
    }


};


int main(){
    //    char* s;
//    gets(s);
//    int result;
//    asm volatile (
//            "mov x0, #5\n\t"      // Завантажуємо 5 в регістр x0
//            "mov x1, #10\n\t"     // Завантажуємо 10 в регістр x1
//            "add %0, x0, x1\n\t"  // Додаємо x0 та x1, результат в %0
//            : "=r" (result)       // Вивідний операнд
//            :                      // Вхідні операнди
//            : "x0", "x1"           // Збережені регістри
//            );
//    std::cout << "Result: " << result << std::endl;

//    int i = 0;
//    start_loop:
//    cout << i << endl;
//    i++;
//    if (i > 10){
//        goto end_loop;
//    }
//    goto start_loop;
//    end_loop:
//    Person p;
//    p.input();
    Friend f("Name", 20000, "0508967854");
//    f.print();
//    cout << f << endl;
//    Person& p = f;
    PhoneBook pb;
    pb.read("friends.txt");
    pb.append(Friend("Polina", 2005, "2282281488"));
    cout << pb.search("Ivan") << endl;
    pb.write("fr_out.txt");

    cout << pb;



}