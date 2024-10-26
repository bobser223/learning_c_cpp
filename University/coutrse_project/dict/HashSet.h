//
// Created by Volodymyr Avvakumov on 26.10.2024.
//
#include <iostream>

#include "LinkedList.h"

#ifndef LEARNING_HASHSET_H
#define LEARNING_HASHSET_H


template<typename var_type>
class HashSet {
protected:
    int real_size;
    int element_count;
    int curr_pow_for_primes;

    LinkedList<var_type>* element_arr;

public:
    HashSet(){
        real_size = 5;
        element_count = 0;
        curr_pow_for_primes = 3;
        element_arr = new LinkedList<var_type>[real_size];
        for (int i = 0; i < 5; i++) element_arr[i].first_el = nullptr;
    }
    void add(var_type var);

    void pop(var_type ver);

    int getSize();

    void print(std::ostream& out = std::cout);

    void debug_print(std::ostream& out = std::cout);

protected:
    int getHash(int var) {
        return var;

    }

    float get_occupancy();

    void create_new_elements_list();

    void copy_list(LinkedList<var_type>* new_lst, int new_size);



    long long next_prime();

    static bool is_prime(long long num);

    friend std::ostream& operator <<(std::ostream& out,const HashSet& set){
        set.print(out);
        return out;
    }
};

//#include "HashSet.cpp"

#endif //LEARNING_HASHSET_H
