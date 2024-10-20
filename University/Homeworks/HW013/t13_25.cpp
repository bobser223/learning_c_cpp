//
// Created by Volodymyr Avvakumov on 17.10.2024.
//

#include <iostream>
#include <string>

struct dict_el{
    char key;
    int value;
};

struct dict{
     dict_el* arr;
    int true_size;
    int curr_size;
};


dict set_dict(){
    dict d;
    d.arr = new dict_el[1];
    d.curr_size = 0;
    d.true_size = 1;
    return d;
}

void kill_dict(dict d){
    delete[] d.arr;
}

void print_d_el(dict_el el){
    std::cout << "key = " << el.key << std::endl;
    std::cout << "value = " << el.value << std::endl;
}

void append(dict& d, char key, int value){
    if (d.curr_size < d.true_size){
        // just ignoring, main logic is in the end;
    } else{
        dict_el* new_arr = new dict_el[d.true_size*2];
        for (int i = 0; i < d.true_size; i++){
            new_arr[i] = d.arr[i];
        }
        delete[] d.arr;
        d.true_size *= 2;
        d.arr = new_arr;

    }
    // FIXME: better to use dict_el* el = new dict_el;

    dict_el el;
    el.key = key;
    el.value = value;


    d.arr[d.curr_size] = el;
    d.curr_size++;
}

bool is_in(dict d, char key, int& key_pos){
    for(int i = 0; i < d.curr_size; i++){
        if (d.arr[i].key == key){
            key_pos = i;
            return true;
        }
    }
    return false;
}

void update_frequency(dict& d, char key){
    int key_pos;
    if (is_in(d, key, key_pos)){
        d.arr[key_pos].value ++;
    } else {
        append(d,key, 1);
    }
}

char find_max(dict d, char char_to_ignore){
    char max_key = d.arr[0].key;
    int max_value = d.arr[0].value;
    for (int i = 1; i < d.curr_size; i++){
        if (d.arr[i].key == char_to_ignore) continue;
        if (d.arr[i].value > max_value){
            max_value = d.arr[i].value;
            max_key = d.arr[i].key;
        }
    }
    return max_key;
}


char find_max(dict d){
    char max_key = d.arr[0].key;
    int max_value = d.arr[0].value;
    for (int i = 1; i < d.curr_size; i++){
        if (d.arr[i].value > max_value){
            max_value = d.arr[i].value;
            max_key = d.arr[i].key;
        }
    }
    return max_key;
}

void find_char(std::string s){
    dict d = set_dict();
    for(char ch: s){
        if ((int)ch < 91 && (int)ch >= 65) ch = (char)((int)ch + 32);
        update_frequency(d, ch);
    }
//    std::cout << find_max(d) << std::endl;
    std::cout << find_max(d, ' ') << std::endl;
//    for (int i = 0; i < d.curr_size; i++){
//        print_d_el(d.arr[i]);
//    }
    kill_dict(d);
}



int main(){
    std::string text = "wbfiuoewldjkewb ewgferyugfhwam,.alohabfhqvyo A fuehfjoirefr";
//    std::string text = "aA bb ccc dDdDdd ffFFFfff O";
    find_char(text);
}