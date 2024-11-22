//
// Created by Volodymyr Avvakumov on 18.11.2024.
//
#include <utility>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

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

map<std::string, int> count_words(const char* filename){
    map<std::string, int> dict;
    std::string text = read_file(filename);
    std::stringstream ss;
    for (char ch : text) {
        if (isalpha(ch) || isspace(ch)) {
            ss << ch;
        }
    }

    std::string word;
    while (ss >> word) {
        if (dict.find(word) != dict.end()) {
            ++dict[word];
        } else {
            dict.insert({word, 1});
        }

    }
    return dict;
}

int main(){
    map<std::string, int> dict = count_words("input01.txt");
    for (const auto& [key, value] : dict) {
        cout << key << ": " << value << endl;
    }
    return 0;
}