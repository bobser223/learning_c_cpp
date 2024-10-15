//
// Created by Volodymyr Avvakumov on 13.10.2024.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

void print_arcsin(double num){
    if (num < -1 || num > 1) {
    } else {
        cout << asin(num) << endl;
    }
}

void print_vec_arcsin(vector<double> vec){
    for(double num : vec){
        print_arcsin(num);
    }
}

void get_doubles_from_string(string input, vector<double> &numbers){
    std::stringstream ss(input);
    std::string temp;

    while (std::getline(ss, temp, ';')) {
        try {
            temp.erase(0, temp.find_first_not_of(" \t"));
            temp.erase(temp.find_last_not_of(" \t") + 1);

            if (!temp.empty()) {
                double num = std::stod(temp);
                numbers.push_back(num);
            }
        } catch (const std::invalid_argument&) {
            std::cerr << "conversion to number error" << std::endl;
        }
    }


}



int read_txt_to_vec(vector<double> &numbers, char* filename){
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        get_doubles_from_string(line, numbers);
//        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}


int main(){
    vector<double> vec;
    read_txt_to_vec(vec, "Homeworks/HW012/doubles.txt");
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    print_vec_arcsin(vec);

    return 0;
}