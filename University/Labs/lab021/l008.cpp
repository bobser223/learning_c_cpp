//
// Created by Volodymyr Avvakumov on 18.11.2024.
//
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
#include <set>

using namespace std;


std::string read_file(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file.");
    }

    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

set<std::string> read_words(const char* filename){
    set<std::string> set;
    std::string text = read_file(filename);
    std::stringstream ss;
    for (char ch : text) {
        if (isalpha(ch) || isspace(ch)) {
            ss << ch;
        }
    }

    std::string word;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}


set<string> same_words(const char* filename1, const char* filename2){
    set<string> intersection;
    set<string> words1 = read_words(filename1);
    set<string> words2 = read_words(filename2);
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), inserter(intersection, intersection.begin()));
    return intersection;
}

set<string> different_words(const char* filename1, const char* filename2){
    set<string> intersection;
    set<string> words1 = read_words(filename1);
    set<string> words2 = read_words(filename2);
    set_symmetric_difference(words1.begin(), words1.end(), words2.begin(), words2.end(), inserter(intersection, intersection.begin()));
    return intersection;
}


int main(){
    set<string> inter =  same_words("input08_1.txt", "input08_2.txt");
    cout << "Intersection: ";
    for (auto elem : inter) {
        cout << elem << " ";
    }
    cout << endl;

    set<string> diff = different_words("input08_1.txt", "input08_2.txt");
    cout << "different words: ";
    for (auto elem : diff) {
        cout << elem << " ";
    }
}