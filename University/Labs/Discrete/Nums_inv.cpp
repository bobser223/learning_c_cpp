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

int count_inversions(const vector<int>& vec) {
    int inversions = 0;
    int n = vec.size();

    // Пробігаємо по всіх парах (i, j) і перевіряємо наявність інверсії
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[i] > vec[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

int total_inversions(const vector<vector<int>>& permutations) {
    int total_inv = 0;

    // Для кожної підстановки рахуємо кількість інверсій і додаємо до загальної суми
    for (const auto& perm : permutations) {
        total_inv += count_inversions(perm);
    }

    return total_inv;
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

int foo(int num, vector<vector<int>> &vect){
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


        vect.push_back(vec);

        for (int j = 0; j < vec.size(); j ++){
            cout << vec[j] << " ";
        }
        cout << " " << endl;

        iterator++;
    }


}


int main(){
    int num;
    cin >> num;
    vector<vector<int>> v;
//    cout << fact(num);
    foo(num, v);
    long a = total_inversions(v);
    cout << a << endl;
    int h = ((num * (num - 1 )) / 4) * fact(num);
    cout << h;
    return 0;
}
