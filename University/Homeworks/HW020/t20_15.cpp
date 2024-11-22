//
// Created by Volodymyr Avvakumov on 22.11.2024.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> input_vector(){
    vector<string> result;
    string word;
    while (true){
        getline(cin, word);
        if (word.empty() || word == "\n"){
            break;
        }
        result.push_back(word);
    }

    return result;
}

map<char, int> chars_map(const vector<string>& vec){
    map<char, int> dict;
    for (auto word: vec){
        char literal = word[0];
        if ((int)(literal) < (int)'a'){
            literal = (char)((int)literal + ('a' - 'A'));

        }
        dict[literal] += word.length();
    }
    return  dict;
}

void count_first_chars(){
    map<char, int> dict = chars_map(input_vector());
    for (auto [a, b]: dict){
        cout << a << " : " << b << endl;
    }
}



int main(){
    count_first_chars();
}