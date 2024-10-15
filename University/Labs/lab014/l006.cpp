//
// Created by Volodymyr Avvakumov on 14.10.2024.
//
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void b(string s){    istringstream iss(s);
    string word;
    int min_size = INT_MAX;
    string min_word;
    while (iss >> word) {
        if (min_size >= word.size()){
            min_word = word;
            min_size = word.size();
        }
//        std::cout << "Слово: " << word << ", Розмір: " << word.size() << std::endl;
    }
    cout << min_word << endl;
}

void c(string s){
    istringstream iss(s);
    string word;
    int min_size = INT_MAX;
    while (iss >> word) {
        if (min_size > word.size()){
            min_size = word.size();
        }

    }

    iss.clear();
    iss.seekg(0, ios::beg);

    while (iss >> word) {
        if (min_size == word.size()){
            cout << word << endl;
        }
    }

}



void a(string s){
    istringstream iss(s);
    string word;
    int min_size = INT_MAX;
    string min_word;
    while (iss >> word) {
        if (min_size > word.size()){
            min_word = word;
            min_size = word.size();
        }
//        std::cout << "Слово: " << word << ", Розмір: " << word.size() << std::endl;
    }
    cout << min_word << endl;
}

int main(){
    string s = "a b aa bbb ccc e o";
//    a(s);
//    b(s);
    c(s);

    return 0;
}

