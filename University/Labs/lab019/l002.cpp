#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class RationalError: public logic_error {
public:
    RationalError(const char* msg) : logic_error(msg) {};
};

class Rational {
private:
    int number;
    int denom;

    void reduce() {
        int d = gcd(number, denom);
        number /= d;
        denom /= d;
    }

    void init(int n, int d) {
        if (d <= 0) throw logic_error("Zero or negative denominator!");
        number = n;
        denom = d;
        reduce();
    }

public:
    Rational(int number, int denom) { init(number, denom); }
    Rational() : number(1), denom(1) {}
    Rational(int number) : number(number), denom(1) {}
    Rational(const Rational& r): Rational(r.number, r.denom) {}

    void input(istream& inp = cin) {
        int n, d;
        inp >> n;
        inp.ignore(256, '/');
        inp >> d;
        init(n, d);
    }

    static int abs(int x) {
        return (x < 0) ? -x : x;
    }

    Rational random() {
        int n = rand() % 200 - 100;
        int d = rand() % 100 + 1;
        return Rational(n, d);
    }

    Rational operator+ () const {return Rational(*this);}
    Rational operator- () const {return Rational(-number, denom);}
    bool operator<(const Rational& other) const {
        double this_num = (double)this->number / this -> denom;
        double other_num = (double)other.number / other.denom;
        return this_num < other_num;
    }
    bool operator>(const Rational& other) const {
        double this_num = (double)this->number / this -> denom;
        double other_num = (double)other.number / other.denom;
        return this_num > other_num;
    }
    bool operator==(const Rational& other) const {
        double this_num = (double)this->number / this -> denom;
        double other_num = (double)other.number / other.denom;
        return this_num == other_num;
    }
    bool operator>=(const Rational& other) const {
        double this_num = (double)this->number / this -> denom;
        double other_num = (double)other.number / other.denom;
        return this_num >= other_num;
    }
    bool operator<=(const Rational& other) {
        double this_num = (double)this->number / this -> denom;
        double other_num = (double)other.number / other.denom;
        return this_num <= other_num;

    }

    void operator=(const Rational& other) {
        this->denom = other.denom;
        this->number = other.number;
    }


    Rational operator+ (const Rational& other) const{
        Rational result(*this);
        result.add(other);
        return result;
    }
    friend Rational operator- (const Rational& self, const Rational& other){
        Rational result = self;
        result.add(-other);
        return result;
    }



    void print(ostream& out = cout) const {
        out << number << "/" << denom;
    }

    static int gcd(int a, int b) {
        while (b > 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    void add(const Rational& other){
        number = number*other.denom + other.number * denom;
        denom = denom*other.denom;
    }

    void multiply(const Rational& other){
        number *= other.number;
        denom *= other.denom;
    }



    friend ostream& operator<<(ostream& out, const Rational& r) {
        r.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Rational& r) {
        r.input(inp);
        return inp;
    }
};

template<class var_t>
var_t bigest(var_t* arr, int arr_size){
    var_t big = arr[0];
    for (int i = 1; i < arr_size; i++){
        std::cout << arr[i] << endl;
        if(arr[i] > big){
            big = arr[i];
        }
    }
    return big;
}

int main() {
//    srand(time(nullptr));
    Rational r(4, 8);
//    r.print();
    Rational arr[4];
    for (int i = 1, j = 3; i < 5; i++, j++){
        arr[i-1]=Rational(i, j);
    }

    std::cout << bigest<Rational>(arr, 4) << std::endl;





}
