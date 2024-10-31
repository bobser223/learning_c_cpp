//
// Created by Volodymyr Avvakumov on 27.10.2024.
//

#include "LinkedList_dict.h"

#ifndef LEARNING_HASHDICT_H
#define LEARNING_HASHDICT_H

template<typename key_t,typename value_t>
class HashDict {
protected:
    int real_size;
    int element_count;
    int curr_pow_for_primes;

    LinkedList_dict<key_t, value_t>* element_arr;
public:
    HashDict(){
        real_size = 5;
        element_count = 0;
        curr_pow_for_primes = 3;
        element_arr = new LinkedList_dict<key_t, value_t>[real_size];
        for (int i = 0; i < 5; i++) element_arr[i].first_el = nullptr;
    }

    ~HashDict(){
        delete[] element_arr;
    }

    void add(key_t key, value_t value){

        if (get_occupancy() > 75)
            create_new_elements_list();

        unsigned position = getHash(key, real_size);

//        std::cout << position <<" " << real_size << std::endl;

        element_arr[position].add(key, value);

        element_count++;
    }

    void pop(key_t key){

        int position = HashDict<key_t, value_t>::getHash(key, real_size);

        if (HashDict<key_t, value_t>::element_arr[position] != nullptr){
            element_arr[position].pop(key);
            element_count --;
        } else{
            throw std::logic_error("no elements here!!!");
        }
    }

    void print(std::ostream& out = std::cout) const {
        for (int i = 0; i < real_size; i++){
            if (element_arr[i] == nullptr) continue;
            out << element_arr[i] << " ";
        }
    }

    bool is_in(key_t key){
        int position = HashDict<key_t, value_t>::getHash(key, real_size);
        return HashDict<key_t, value_t>::element_arr[position].is_in(key);
    }

//    value_t operator[](key_t key) const {
//        int position = HashDict<key_t, value_t>::getHash(key, real_size);
//        return element_arr[position];
//    }

    value_t& operator[](key_t key) {
        int position = HashDict<key_t, value_t>::getHash(key, real_size);
        return element_arr[position][key];
    }

    const value_t& operator[](key_t key) const {
        int position = getHash(key, real_size);
        return element_arr[position][key];
    }


protected:

    void add_to_array(LinkedList_dict<key_t, value_t>* arr,int arr_size, key_t key, value_t value){
        int position = getHash(key, arr_size);
        arr[position].add(key, value);
    }

    template <typename T>
    typename std::enable_if<std::is_integral<T>::value, long long int>::type
    getHash(T value, int size) const {
        long long int result = 0;
        while (value) {
            result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
            result ^= (value & 0xFF);
            value >>= 8;
        }

        return result % size;
    }

    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, long long int>::type
    getHash(T value, int size) const {
        long long int result = 0;
        unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&value);
        for (size_t i = 0; i < sizeof(T); ++i) {
            result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
            result ^= bytePtr[i];
        }

        return result % size;
    }

    template <typename T>
    typename std::enable_if<std::is_pointer<T>::value, long long int>::type
    getHash(T value, int size) const {
        long long int result = 0;
        uintptr_t ptr = reinterpret_cast<uintptr_t>(value);
        unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&ptr);
        for (size_t i = 0; i < sizeof(ptr); ++i) {
            result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
            result ^= bytePtr[i];
        }
        return result % size;
    }

    [[nodiscard]] long long int getHash(const std::string& value, int size) const{
        long long int result = 0;
        for (char c : value) {
            result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
            result ^= static_cast<unsigned char>(c);
        }
        return result % size;
    }
    // for random type;
    template <typename T>
    typename std::enable_if<!std::is_integral<T>::value &&
                            !std::is_floating_point<T>::value &&
                            !std::is_pointer<T>::value, long long int>::type
    getHash(const T& value, int size) const {
        long long int result = 0;
        const unsigned char* bytePtr = reinterpret_cast<const unsigned char*>(&value);
        for (size_t i = 0; i < sizeof(T); ++i) {
            result = (result << 5) | (result >> (sizeof(long long int) * 8 - 5));
            result ^= bytePtr[i];
        }
        return (result % size);
    }
public: //TODO protected
    float get_occupancy(){
        if (real_size == 0) return 0;
        return ((float)element_count / real_size) * 100;
    }

    void create_new_elements_list() {
        long long new_size = HashDict<key_t, value_t>::next_prime();

        LinkedList_dict<key_t, value_t>* new_element_arr = new LinkedList_dict<key_t, value_t>[new_size];

        HashDict<key_t, value_t>::copy_list(new_element_arr, new_size);

        delete[] HashDict<key_t, value_t>::element_arr;
        element_arr = new_element_arr;
        HashDict<key_t, value_t>::real_size = new_size;
    }

    void copy_list(LinkedList_dict<key_t, value_t>* new_lst, int new_size){ // hurd
        for (int i = 0; i < real_size; i ++){
            if (element_arr[i] != nullptr){
                for (int j = 0; j < element_arr[i].get_size(); j++){
                    Couple<key_t, value_t> c = element_arr[i].get_couple(j);
                    add_to_array(new_lst, new_size, c.key, c.value);
                }
            }
        }

    }

    long long next_prime(){
        long long min_lim = pow(2, curr_pow_for_primes);
        long long max_lim = pow(2, curr_pow_for_primes+1);

        long long middle = (min_lim + max_lim) / 2;
        for (long long i = middle; i < max_lim - 1; i++){
            if (HashDict<key_t, value_t>::is_prime(middle - i)){
                curr_pow_for_primes ++;
                return middle - i;
            }
            if (HashDict<key_t, value_t>::is_prime(middle + i)){
                curr_pow_for_primes ++;
                return middle + i;
            }
        }
        // if no primes from 2^k-1 to 2^k;
        curr_pow_for_primes ++;
        return HashDict<key_t, value_t>::next_prime();
    }

    static bool is_prime(long long num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        int sqrt_num = static_cast<long long>(std::sqrt(num)); //FIXME !!!!!!!!!!!!!!! ststic_cast<int>
        for (long long i = 5; i <= sqrt_num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    friend std::ostream& operator <<(std::ostream& out,const HashDict& dict){
        dict.print(out);
        return out;
    }





};


#endif //LEARNING_HASHDICT_H
