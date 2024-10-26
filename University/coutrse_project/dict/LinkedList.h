//
// Created by Volodymyr Avvakumov on 26.10.2024.
//

#ifndef LEARNING_LINKEDLIST_H
#define LEARNING_LINKEDLIST_H

template<typename var_type>
struct ListEl{
    var_type var;
    ListEl<var_type>* next_pointer;
};

template<typename var_type>
class LinkedList {

private:
    int size;
    ListEl<var_type>* first_el;

public:

    LinkedList() : first_el(nullptr), size(0) {}


    void add(var_type var){
        ListEl<var_type>* new_el = new ListEl<var_type>;
        new_el -> var = var;
        new_el -> next_pointer = nullptr;
        if (size == 0){
            first_el = new_el;
        } else {
            ListEl<var_type>* curr_el = first_el;
            while (curr_el -> next_pointer != nullptr){
                curr_el = curr_el -> next_pointer;
            }
            curr_el -> next_pointer = new_el;
        }

        size ++;

    }
};


#endif //LEARNING_LINKEDLIST_H
