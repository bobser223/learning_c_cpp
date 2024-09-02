//
// Created by Volodymyr Avvakumov on 27.08.2024.
//

#include <iostream>

#include "FigureList.cpp"

using namespace std;

class MaxFinder{
    string file;
    FigureList fl;
    vector<shared_ptr<Figure>> figures;
public:
    MaxFinder(string a_file){
        file = a_file;
        FigureList fl2(file);
        fl = fl2;
        vector<shared_ptr<Figure>> figures2 = fl.fill_list();
        figures = figures2;
    }

    auto findChemp(){
        auto maxFigure = figures[0];
        int maxPer = maxFigure -> perimeter();
        double maxArea = maxFigure -> area();
        for (int i = 1; i < figures.size() - 1; i++ ){
            auto currFigure = figures[i];
            int currPer = currFigure -> perimeter();
            float currArea = currFigure -> area();
            if (currPer > maxPer && currArea > maxArea){
                maxFigure = currFigure;
                maxPer = currPer;
                maxArea = currArea;
            }
        }
        return maxFigure;
    }

};

int main(){
    MaxFinder mf("input01.txt");
    auto winner = mf.findChemp();
    winner -> printMe();

}
