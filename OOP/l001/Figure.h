//
// Created by Volodymyr Avvakumov on 26.08.2024.
//

#ifndef LEARNING_FIGURE_H
#define LEARNING_FIGURE_H


using namespace std;

class Figure{
public:

    virtual int perimeter() const = 0;

    virtual double area()const = 0;

    virtual void printMe(){
        cout << "aaa" << endl;
    }



};



#endif //LEARNING_FIGURE2_H
