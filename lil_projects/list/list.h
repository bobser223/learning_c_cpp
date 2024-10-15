//
// Created by Volodymyr Avvakumov on 09.10.2024.
//

#include <iostream>
#include <typeinfo>

#ifndef LEARNING_LIST_H
#define LEARNING_LIST_H


template <typename T>
struct element {
    T var;
    element* next_pointer;
    element() : var(), next_pointer(nullptr) {}
    element(T v) : var(v), next_pointer(nullptr) {}
};



class list {
private:
    element<void*>* el;

public:

    int size;


    list() : el(nullptr), size(0) {}


    template<typename T2>
    void append(T2 var) {
        element<void*>* new_el = new element<void*>((void*)(new T2(var)));
        size = 0;
        if (size == 0) {
            el = new_el;
        } else {
            element<void*>* curr_el = el;
            while (curr_el -> next_pointer != nullptr) {
                curr_el = curr_el -> next_pointer;
            }
            curr_el -> next_pointer = new_el;
        }

        size ++;
    };

    void display() {
        element<void*>* curr_el = el;
        while (curr_el != nullptr) {
            std::cout << *(static_cast<int*>(curr_el->var)) << " ";
            curr_el = curr_el->next_pointer;
        }
        std::cout << std::endl;
    }

//    auto operator[](int index) {
//        if (index < 0 || index >= size) {
//            throw std::out_of_range("Index out of range");
//        } else {
//            element* curr_el = el;
//            for (int i = 0; i < index; i++) {
//                curr_el = curr_el->next_pointer;
//            }
//            return curr_el->var;
//
//        }
//    }

//    friend std::ostream& operator<<(std::ostream& os, const list& l) {
//        element* curr_el = l.el;
//        while (curr_el != nullptr) {
//            os << *curr_el << " ";
//            curr_el = curr_el->next_pointer;
//        }
//        return os;
//    }


    int len(){
        return size;
    }


};


#endif //LEARNING_LIST_H
