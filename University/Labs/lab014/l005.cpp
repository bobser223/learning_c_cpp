//
// Created by Volodymyr Avvakumov on 14.10.2024.
//
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
using namespace std;

void part_split(int n, string s, string* arr){
    stringstream ss(s);
    int j = 0;
    int i = 0;
    for (int _ = 0; _ < n; _++){
        j = s.find(' ', i);
        arr[_] = s.substr(i, j - i);
//        cout << s.substr(i, j - i) << endl;
        i = j + 1;
    }


}


int main(){
    int n = 4;
    string s = "buerygfuiw, wehfiwepn;fjweoi, wbufehfuiweifuhewpui, fuwehfew, feruihfiuer, uerohgiuoerho, ueribguio";
    string* arr = new string[n];
    part_split(n, s, arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}