//
// Created by Volodymyr Avvakumov on 17.10.2024.
//
#include <iostream>
#include <string>


using namespace std;

struct int_arr{
    int* arr;
    int true_size;
    int curr_size;
};

int_arr set_int_arr(int size){
    if (size == 0) size = 1; // monkey assumption
    int_arr i_arr;
    i_arr.arr = new int[size];
    i_arr.curr_size = size;
    i_arr.true_size = size;
    return i_arr;
}

void append(int_arr& i_arr, int var){
    if (i_arr.curr_size < i_arr.true_size){
            // just ignoring, main logic is in the end;
    } else{
        int* new_arr = new int[i_arr.true_size*2];
        for (int i = 0; i < i_arr.true_size; i++){
            new_arr[i] = i_arr.arr[i];
        }
        delete[] i_arr.arr;
        i_arr.true_size *= 2;
        i_arr.arr = new_arr;

    }

    i_arr.arr[i_arr.curr_size] = var;
    i_arr.curr_size++;
}



std::string replace_spaces(string& str){
    std::string result;
    bool wasSpace = false;

    for (char ch : str) {
        if (ch == ' ') {
            if (!wasSpace) {
                result += ',';
                wasSpace = true;
            }
        } else {
            result += ch;
            wasSpace = false;
        }
    }
    if (str.ends_with('.')){

    } else result += '.';
    return result;

}


int main(){
    std::string base_string = "iohwef  ioewoi  fjop   we";
    std::string new_string = replace_spaces(base_string);
    std::cout << new_string << std::endl;

    return 0;
}