//
// Created by Volodymyr Avvakumov on 22.11.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>



void read_dates(char* filename){
    std::vector<std::string> dates;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не вдалося відкрити файл." << std::endl;
    }

    std::string line;
    while (getline(file, line)) {
        dates.push_back(line);
    }

    file.close();


//    for (auto& date: dates){
//        std::transform(date.begin(), date.end(), date.begin(), [](char c) {if (c == '.'){ return '/';} else {return c;}});
//    }

    for(auto& date: dates){
        std::replace(date.begin(), date.end(), '.', '/');
    }

    std::sort(dates.begin(), dates.end());
    auto last = std::unique(dates.begin(), dates.end());
    dates.erase(last, dates.end());

    for(const auto& date: dates){
        std::cout << date << std::endl;
    }
}




int main(){
    read_dates("input14.txt");
}