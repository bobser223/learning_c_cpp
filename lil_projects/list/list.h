//
// Created by Volodymyr Avvakumov on 09.10.2024.
//

#include <iostream>
#include <typeinfo>

#ifndef LEARNING_LIST_H
#define LEARNING_LIST_H


using var_type = std::variant<int, float, char, std::string>;



struct element {
    var_type var;
    std::string type;
    element* next_pointer;
    element() : var(), next_pointer(nullptr) {}
    element(var_type v) : var(v), next_pointer(nullptr) {}
};

std::ostream& operator<<(std::ostream& os, const element& el) {
    std::visit([&os](auto&& arg) {
        os << arg;
    }, el.var);
    return os;
}


class list {
private:
    element* el;

public:

    int size;


    list() : el(nullptr), size(0) {}


    template<typename T2>
    void append(T2 var) {
        element* new_el = new element(var);
        if (el == nullptr) {
            el = new_el;
        } else {
            element* curr_el = el;
            while (curr_el->next_pointer != nullptr) {
                curr_el = curr_el->next_pointer;
            }
            curr_el -> next_pointer = new_el;
        }

        size ++;
    };

    var_type& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        } else {
            element* curr_el = el;
            for (int i = 0; i < index; i++) {
                curr_el = curr_el->next_pointer;
            }
            return curr_el->var;

        }
    }

    friend std::ostream& operator<<(std::ostream& os, const list& l) {
        element* curr_el = l.el;
        while (curr_el != nullptr) {
            os << *curr_el << " ";
            curr_el = curr_el->next_pointer;
        }
        return os;
    }


    int len(){
        return size;
    }


};


#endif //LEARNING_LIST_H
