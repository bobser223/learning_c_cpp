//
// Created by Volodymyr Avvakumov on 24.10.2024.
//

#include <iostream>
#include <cmath>
#include <optional>



class Point{
private:
    double x;
    double y;

    void init(double a, double b){
        this-> x = a;
        this-> y = b;
    }


public:
    Point(double x, double y): x(x), y(y) {};
    Point(){};

    bool operator== (const Point& other) const{
        if (this -> x == other.x && this -> y == other.y) return true;
        return false;
    }

    void input(std::istream& inp = std::cin){
        double a, b;
        inp >> a;
        inp.ignore(256, ',');
        inp >> b;
        init(a, b);
    }

    double get_x() const{
        return x;
    }

    double get_y() const{
        return y;
    }


    void print(std::ostream& out = std::cout) const{
        out << '('<< this->x << ',' << this->y <<')';
    }

    // for printing through default operator cout << Point;
    friend  std::ostream& operator <<(std::ostream& out,const Point& p){
        p.print(out);
        return out;
    }

    // for input through default operator cin >> Point;
    friend std::istream& operator >>(std::istream& inp, Point& p){
        p.input(inp);
        return inp;
    }


    friend class Segment;
    friend class Triangle;
};

class Segment{
private:
    Point p1;
    Point p2;

    void init(double a1, double b1, double a2, double b2){
        this -> p1.init(a1, b1);
        this -> p2.init(a2, b2);
        if (this -> p1 == this -> p2) throw std::logic_error("This is a point, not segment");
    }

    void init(Point p_1, Point p_2){
        this -> p1 = p_1;
        this -> p2 = p_2;
    }

public:
    Segment(double a1, double b1, double a2, double b2) {init(a1, b1, a2, b2);}
    Segment(): p1(NAN, NAN), p2(NAN, NAN) {}


    double get_length() const{
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    void input(std::istream& inp = std::cin){
        double a1, b1, a2, b2;
        inp >> a1;
        inp.ignore(256, ',');
        inp >> b1;
        inp.ignore(256, ',');
        inp >> a2;
        inp.ignore(256, ',');
        inp >> b2;
        init(a1, b1, a2, b2);
    }

    void print(std::ostream& out = std::cout) const{
        out << p1 << "|------------|" << p2;
    }

    static bool onSegment(Point p, Point q, Point r) {
        return (q.get_x() <= std::max(p.get_x(), r.get_x()) && q.get_x() >= std::min(p.get_x(), r.get_x()) &&
                q.get_y() <= std::max(p.get_y(), r.get_y()) && q.get_y() >= std::min(p.get_y(), r.get_y()));
    }

    static int orientation(Point p, Point q, Point r) {
        double val = (q.get_y() - p.get_y()) * (r.get_x() - q.get_x()) - (q.get_x() - p.get_x()) * (r.get_y() - q.get_y());
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }

    Point intersection(Segment& other) {
        Point p_NUN(NAN, NAN);

        Point A = this->p1;
        Point B = this->p2;
        Point C = other.p1;
        Point D = other.p2;

        double a1 = B.get_y() - A.get_y();
        double b1 = A.get_x() - B.get_x();
        double c1 = a1 * A.get_x() + b1 * A.get_y();

        double a2 = D.get_y() - C.get_y();
        double b2 = C.get_x() - D.get_x();
        double c2 = a2 * C.get_x() + b2 * C.get_y();

        double determinant = a1 * b2 - a2 * b1;

        if (determinant == 0) {
            return p_NUN;
        } else {
            double x = (b2 * c1 - b1 * c2) / determinant;
            double y = (a1 * c2 - a2 * c1) / determinant;
            Point intersectionPoint(x, y);


            if (onSegment(this->p1, intersectionPoint, this->p2) && onSegment(other.p1, intersectionPoint, other.p2)) {
                return intersectionPoint;
            }

            return p_NUN;
        }
    }

    friend  std::ostream& operator <<(std::ostream& out, const Segment& s){
        s.print(out);
        return out;
    }

    friend std::istream& operator >>(std::istream& inp, Segment& s){
        s.input(inp);
        return inp;
    }


    friend class Triangle;
};


class Triangle{
private:
    Point vertex1;
    Point vertex2;
    Point vertex3;

    Segment side1;
    Segment side2;
    Segment side3;
public:
    Triangle(double a1,double b1,double a2,double b2,double a3, double b3){ init(a1, b1, a2, b2, a3, b3);}
    Triangle(){};
public:
    double perimeter() const{
        return side1.get_length() + side2.get_length() + side3.get_length();
    }

    double area()  const{
        double p = perimeter() / 2;
        return sqrt(p*(p - side1.get_length())*(p - side2.get_length())*(p - side3.get_length()));
    }

    void print(std::ostream& out = std::cout) const{
        out << vertex1 << ';' << vertex2 << ';' << vertex3;
    }

    void input(std::istream& inp = std::cin){
        double a1, b1,a2, b2,a3, b3;
        inp >> a1;
        inp.ignore(256, ',');
        inp >> b1;
        inp.ignore(256, ',');
        inp >> a2;
        inp.ignore(256, ',');
        inp >> b2;
        inp.ignore(256, ',');
        inp >> a3;
        inp.ignore(256, ',');
        inp >> b3;
        init(a1, b1, a2, b2, a3, b3);
    }

    friend  std::ostream& operator <<(std::ostream& out, const Triangle& t){
        t.print(out);
        return out;
    }

    friend std::istream& operator >>(std::istream& inp, Triangle& t){
        t.input(inp);
        return inp;
    }

private:
    void init(double a1,double b1,double a2,double b2,double a3, double b3){
        vertex1.init(a1, b1);
        vertex2.init(a2, b2);
        vertex3.init(a3, b3);

        side1.init(vertex1, vertex2);
        side2.init(vertex2, vertex3);
        side3.init(vertex3, vertex1);
    }





};

int main(){
    Point p1(2, 3);
    std::cout << p1 << std::endl;
    Point p2;
    std::cin >>p2;
    std::cout << p2 << std::endl;
    std::cout << (p2 == p1) << std::endl;
    p2.input();

    Segment s1(1, 2, 3, 4);
    Segment s2(-1, 0, 2, 7);
    std::cout << s1 << std:: endl;
    std::cout << s2 << std:: endl;
    std::cout << s1.intersection(s2) << std:: endl;
    Segment s3(-2,-1, 3, 4);
    Segment s4(-1, 0, 2, 7);
    std::cout << s3 << std:: endl;
    std::cout << s4 << std:: endl;
    std::cout << s3.intersection(s4) << std:: endl;
    Segment s5(2,2,4,2);
    Segment s6(3, 1, 3,3);
    std::cout << s5 << std:: endl;
    std::cout << s6 << std:: endl;
    std::cout << s5.intersection(s6) << std:: endl;

    Segment s;
    std::cin >>s;
    std::cout << s << std::endl;


    Triangle t1(3, 1, 5, 1, 3, 6);
    std::cout << t1 << std:: endl;
    std::cout << t1.perimeter() << std:: endl;
    std::cout << t1.area() << std:: endl;

    Triangle t2;
    std::cin >> t2;
    std::cout << t2 << std:: endl;
    std::cout << t2.perimeter() << std:: endl;
    std::cout << t2.area() << std:: endl;

    return 0;
}
