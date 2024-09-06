//
// Created by Volodymyr Avvakumov on 03.09.2024.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

long int fact(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int find_max_num(vector<int> &vec, string &str, int &max_num, int &max_iter, int &pos){
    int max_n = -1;
    int max_i = -1;

    int start;
    if (str[0] == 'r'){
        start = 0;
    } else {
        start = 1;
    }

    for (int i = start; i < vec.size(); i++){
        if (str[i] == 'r' &&  i < vec.size() - 1 && vec[i] >= max_n && vec[i] >=vec[i+1]){ // TODO: maybe <= vec.size
            max_n = vec[i];
            max_i = i;
            pos = 1;
        } else if (str[i] == 'l' && vec[i] > max_n && vec[i] > vec[i-1] ) {
            max_n = vec[i];
            max_i = i;
            pos = -1;
        }

    }
    if (max_n == -1 && max_i == -1){
        return 1;

    } else {
        for (int i = 0; i < vec.size(); i ++){
            if (vec[i] > max_n ){
                if (str[i] == 'l'){
                    str[i] = 'r';
                } else if (str[i] == 'r'){
                    str[i] = 'l';
                }
            }
        }
        max_num = max_n;
        max_iter = max_i;
        return 0;
    }

}

int foo(int num){
    if (num == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<int> vec;
    string str;


    for (int i = 1; i <= num; i++){
        vec.push_back(i);
        str += 'l';
    }
    int iterator = 0;


    for (int j = 0; j < vec.size(); j ++){
        cout << vec[j] << " ";
    }
    cout << " " << endl;

    while (true){
        int max_num, max_iter, pos_pointer;
        int break_catcher = find_max_num(vec, str, max_num, max_iter, pos_pointer);
        if (break_catcher){
            break;
        }
        char buf;
        buf = vec[max_iter];
        vec[max_iter] = vec[max_iter + pos_pointer];
        vec[max_iter + pos_pointer] = buf;
        char c;
        c = str[max_iter];
        str[max_iter] = str[max_iter + pos_pointer];
        str[max_iter + pos_pointer] = c;

//        for (int j = 0; j < vec.size(); j ++){
//            if (str[j] == 'l'){
//                cout << "<-"<< " ";
//            } else {
//                cout << "->"<< " ";
//            }
//        }
//        cout << " " << endl;

        for (int j = 0; j < vec.size(); j ++){
            cout << vec[j] << " ";
        }
        cout << " " << endl;
//        if (iterator >= fact(num)){
//            break;
//        }
//        cout << iterator;
        iterator++;
    }


}


int main(){
    int num;
    cin >> num;
//    cout << fact(num);
    foo(num);
    return 0;
}