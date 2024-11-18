//
// Created by Volodymyr Avvakumov on 15.11.2024.
//
#include <iostream>
#include <vector>

using namespace std;

void vector_example(){
    vector<int> v(10);

    for (auto x:v){
        cout << x << endl;
    }
}


int main(){
    vector_example();
}