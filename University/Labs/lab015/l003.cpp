//
// Created by Volodymyr Avvakumov on 18.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void get_words(string s){
    string cleaned;
    for (char c : s) {
        if (!ispunct(c)) {
            cleaned += c;
        }
    }
    stringstream ss(cleaned);
    string word;
    while(ss >> word){
        reverse(word.begin(), word.end());
        cout << word << endl;
    }
}

void foo(char* filename){
    fstream f;
    f.open(filename, f.in);
    string s;
    while(f.good()){
        getline(f, s);
        get_words(s);
    }
    f.close();
}


int main(){
    foo("inp02.txt");


}