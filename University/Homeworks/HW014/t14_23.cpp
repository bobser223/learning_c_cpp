//
// Created by Volodymyr Avvakumov on 22.10.2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool is_void(std::string line){
    if(line.size() == 0){
        return true;
    }
    for(char ch: line){
        if (ch != '\n' || ch != ' '){
            return false;
        }
    }
    return true;
}

int void_lines_count(char* filename){
    int count = 0;
    std::fstream f;
    f.open(filename, f.in);
    std::string line;
    while (f.good()){
        getline(f, line);
        if (is_void(line)){
            count += 1;
        }

    }
    f.close();
    return count;
}

int largest_line(char* filename){
    int max_size = 0;
    std::fstream f;
    f.open(filename, f.in);
    std::string line;
    while (f.good()){
        getline(f, line);
        if (line.size() > max_size) max_size = line.size();

    }
    f.close();
    return max_size;
}


int main(){
    std::cout << void_lines_count("input14_23.txt") << std::endl;
    std::cout << largest_line("input14_23.txt") << std::endl;
    return 0;
}