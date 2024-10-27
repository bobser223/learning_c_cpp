//
// Created by Volodymyr Avvakumov on 27.10.2024.
//

#ifndef LEARNING_LINKEDLIST_DICT_H
#define LEARNING_LINKEDLIST_DICT_H


template<typename key_type, typename value_type>
struct ListEl{
    bool is_empty;
    key_type key;
    value_type value;
    ListEl<key_type, value_type>* next_pointer;
};

template<typename key_type, typename value_type>
class LinkedList_dict {
private:
    int size;
    ListEl<key_type, value_type>* first_el;
public:
    void add(key_type key, value_type value){
        if(is_in(key))  return;
        ListEl<key_type, value_type>* new_el = new ListEl<key_type, value_type>;
        new_el -> key = key;
        new_el -> value = value;
        new_el -> next_pointer = nullptr;
        new_el ->is_empty = false;
        if (size == 0){
            first_el = new_el;
        } else {
            ListEl<key_type, value_type>* curr_el = first_el;
            while (curr_el -> next_pointer != nullptr){
                curr_el = curr_el -> next_pointer;
            }
            curr_el -> next_pointer = new_el;
        }

        size ++;

    }

    bool is_in(key_type key){
        if (size == 0){
//            throw std::logic_error("no elements here!!!");
            return false;
        } else {

            ListEl<key_type, value_type>* curr_el = first_el;
            while (curr_el != nullptr){
                if (curr_el->key == key && !curr_el->is_empty) return true;
                curr_el = curr_el->next_pointer;
            }
            return false;
        }
    }

    void pop(var_type var){ //todo: refactor!!!!!!!
        if (!is_in(var)){
            throw std::logic_error("this variable isn't here!!!");
        }

        if (size == 1){
            delete first_el;
            first_el = nullptr;
        } else if (first_el->var == var){
            ListEl<var_type>* temp = first_el;
            first_el = first_el->next_pointer;
            delete temp;
        } else {
            ListEl<var_type>* previous_element = nullptr;
            ListEl<var_type>* element_to_delete = nullptr;
            find_element_with_var(var, previous_element, element_to_delete);

            if (element_to_delete != nullptr && previous_element != nullptr){
                previous_element->next_pointer = element_to_delete->next_pointer;
                delete element_to_delete;
            }
        }

        size--;
    }


};


#endif //LEARNING_LINKEDLIST_DICT_H
