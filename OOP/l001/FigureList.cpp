//
// Created by Volodymyr Avvakumov on 26.08.2024.
//
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "FileReader.cpp"
#include "Figure.h"
#include "Circle.cpp"
#include "Parallelogram.cpp"
#include "Rectangle.cpp"
#include "Trapeze.cpp"
#include "Triangle.cpp"


class FigureList{
    vector<shared_ptr<Figure>> figures;
    string file;
    FileReader fr;
    // TODO: end
//    int to_int(auto num){
//        if
//    }
public:
    explicit FigureList(string a_file){
        file = a_file;
        FileReader fr2(a_file);
        fr = fr2;
    }
    FigureList(){}
    vector<shared_ptr<Figure>>  fill_list(){
        vector<vector<string>> data = fr.read();
        for (int i = 0; i < data.size() - 1; i++){
//            for (int j = 0; j < data[i].size(); j ++){
//                cout << data[i][j] << " ";
//            }
//            cout << "" << endl;
            string currClass = data[i][0];
            if (currClass == "Circle"){
                figures.push_back(make_shared<Circle>(stoi(data[i][1])));
            } else if (currClass == "Trapeze") {
                figures.push_back(make_shared<Trapeze>(stoi(data[i][1]), stoi(data[i][2]), stoi(data[i][3]), stoi(data[i][4])));
            } else if (currClass == "Rectangle") {
                figures.push_back(make_shared<Rectangle>(stoi(data[i][1]), stoi(data[i][2])));
            } else if (currClass == "Parallelogram") {
                figures.push_back(make_shared<Parallelogram>(stoi(data[i][1]), stoi(data[i][2]), stoi(data[i][3])));
            } else if (currClass == "Triangle") {
                figures.push_back(make_shared<Triangle>(stoi(data[i][1]), stoi(data[i][2]), stoi(data[i][3])));
            } else {
                continue;
            }
        }
        return figures;
    }
};

//int main(){
//    FigureList fl("input01.txt");
//
//    vector<shared_ptr<Figure>> rrr = fl.fill_list();
//    for (int i = 0; i < rrr.size() - 1; i++){
//        rrr[i] -> printMe();
//        cout << rrr[i] -> perimeter() << endl;
//        cout << rrr[i] -> area() << endl;
//    }
//    return 0;
//
//}