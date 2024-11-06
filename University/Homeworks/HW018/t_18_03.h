//
// Created by Volodymyr Avvakumov on 05.11.2024.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef LEARNING_T_18_03_H
#define LEARNING_T_18_03_H

template <typename T>
struct element{
    T value;
    element* next;
};


template <typename T>
class BlackBox {
private:
    element<T>* curr_el;
    int size = 0;
public:
    BlackBox() {
        srand(static_cast<unsigned>(time(0)));
        curr_el = nullptr;
    }

    BlackBox(T* arr, int arr_size){
        curr_el = nullptr;
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < arr_size; i++){
            push(arr[i]);
        }
    }

    ~BlackBox() {
        element<T>* temp;
        while (curr_el != nullptr) {
            temp = curr_el;
            curr_el = curr_el->next;
            delete temp;
        }
    }

    void push(T var);

    T pop();

    T xpop();

protected:

};
// public

template<typename T>
void BlackBox<T>::push(T var) {
    if(size == 100) throw std::logic_error("Serso, already 100 elements");
    element<T>* new_el = new element<T>;
    new_el -> value = var;
    new_el -> next = curr_el;
    curr_el = new_el;
    size ++;
}

template<typename T>
T BlackBox<T>::pop() {
    if(curr_el == nullptr) throw std::logic_error("Serso, BB is empty");
    int randomNumber = rand() % size;
    element<T>* el_to_pop = curr_el;
    element<T>* previous = nullptr;

    for (int i = 0; i < randomNumber; i++){
        previous = el_to_pop;
        el_to_pop = el_to_pop ->next;
    }
    T output = el_to_pop ->value;

    if(randomNumber == 0){
        curr_el = el_to_pop -> next;
    } else {
        previous ->next = el_to_pop ->next;
    }
    delete el_to_pop;
    size --;
    return output;
}

template<typename T>
T BlackBox<T>::xpop() {
    if(curr_el == nullptr) throw std::logic_error("Serso, BB is empty");
    int randomNumber = rand() % size;
    element<T>* el_to_pop = curr_el;
    for (int i = 0; i < randomNumber; i++){
        el_to_pop = el_to_pop ->next;
    }
    return  el_to_pop ->value;
}




// protected




#endif //LEARNING_T_18_03_H
