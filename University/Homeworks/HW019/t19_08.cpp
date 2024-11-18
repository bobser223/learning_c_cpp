//
// Created by Volodymyr Avvakumov on 18.11.2024.
//
#include <list>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>

struct ls{
    list<T> lst;

    void operator+=(T num){
        lst.push_back(num);
    }

    void operator-=(T num){
        lst.remove(num);
    }

    T find_nearest(T num){
        T nearest = lst.front();
        T curr_distance = fabs(nearest - num);
        for (const auto& elem : lst) {
            T distance = fabs(elem - num);
            if (distance < curr_distance) {
                curr_distance = distance;
                nearest = elem;
            }
        }
        return nearest;
    }

    void print(ostream& out = cout) const{
        for (const auto& el: lst){
            out << el << " ";
        }
    }
    friend ostream& operator << (std::ostream& out, const ls& l) {
        l.print(out);
        return out;
    }
};


int main(){
    ls<double> l;
    for (int i = 0; i < 6; i++){
        l += i;
    }

    cout << l << endl;

    double x = 2.5;
    cout << l.find_nearest(x) << endl;
    x = 2.6;
    cout << l.find_nearest(x) << endl;

    l -= 3;

    cout << l << endl;
}