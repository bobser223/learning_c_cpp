#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


class Rational {

private:

    int numer;
    int denom;

    void init(int n, int d) {
        if (d <= 0)
            throw logic_error("Zero or negative denominator!");
        numer = n;
        denom = d;
        reduce();
    }

    void reduce() {
        int d = gcd(abs(numer), denom);
        numer /= d;
        denom /= d;
    }

public:

    Rational(int numer, int denom) {init(numer, denom);}
    Rational(): numer(1), denom(1) {}
    Rational(int numer): numer(numer), denom(1) {}
    Rational(const Rational& r): Rational(r.numer, r.denom) {}

    static Rational random() {
        int n = rand() % 200 - 100;
        int d = rand() % 100 + 1;
        return Rational(n, d);
    }

    void print(ostream& out = cout) const {
        out << numer << '/' << denom;
    }

    void input(istream& inp = cin) {
        int n, d;
        inp >> n;
        inp.ignore(256, '/');
        inp >> d;
        init(n, d);
    }

    void add(const Rational& other) {
        numer = numer * other.denom + other.numer * denom;
        denom = denom * other.denom;
        reduce();
    }
    void multiply(const Rational& other) {
        numer *= other.numer;
        denom *= other.denom;
        reduce();
    }

    Rational operator+ () const {return Rational(*this);}
    Rational operator- () const {return Rational(-numer, denom);}

    bool operator< (const Rational& other) const {return numer * other.denom < other.numer * denom;}
    bool operator< (double x) const {return numer < x * denom;}
    bool operator> (const Rational& other) const {return numer * other.denom > other.numer * denom;}
    bool operator> (double x) const {return numer > x * denom;}
    bool operator<= (const Rational& other) const {return numer * other.denom <= other.numer * denom;}
    bool operator>= (const Rational& other) const {return numer * other.denom >= other.numer * denom;}
    bool operator== (const Rational& other) const {return numer == other.numer && denom == other.denom;}
    bool operator!= (const Rational& other) const {return numer != other.numer || denom != other.denom;}

    Rational& operator+= (const Rational& other){ add(other); return *this;}

    Rational operator+ (const Rational& other) const {
        Rational result(*this);
        result.add(other);
        return result;
    }
    friend Rational operator- (const Rational& self, const Rational& other) {
        Rational result(self);
        result.add(-other);
        return result;
    }
    Rational operator*(const Rational& other) const {
        Rational result(*this);
        result.multiply(other);
        return result;
    }

    double to_double() {return (double) numer / denom;}

    static int abs(int x)  {
        return (x < 0) ? -x : x;
    }

    static Rational abs(const Rational& r) {
        return (r < 0) ? Rational(-r) : Rational(r);
    }

    static int gcd(int a, int b) {
        while (b > 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    friend ostream& operator<< (ostream& out, const Rational& r) {
        r.print(out);
        return out;
    }

    friend istream& operator>> (istream& inp, Rational& r) {
        r.input(inp);
        return inp;
    }

};

float pi(double eps=0.009){
    Rational s(1,1), a(1,1);
    int i = 1;
    while (Rational::abs(a) > eps){
        i ++;
        a = Rational(i % 2 ? 1 : -1, i*i);
        s += a;

//        cout << a << endl;
    }
    cout << sqrt(12.0 * s.to_double()) << endl;
    return sqrt(12.0 * s.to_double());
}


int main() {
    srand(time(nullptr));

    const int N = 4;
    Rational array[N] = {
            Rational(1, 2),
            Rational(5),
            Rational(),
            Rational::random()
    };
    // array[0].input();
    // cin >> array[0];
    // array[0].add(Rational(1, 3));
    array[0] = array[0] - Rational(1, 3);

    for (int i = 0; i < N; i++) {
        cout << array[i] << endl;
    }

    cout << pi() << endl;

    return 0;
}