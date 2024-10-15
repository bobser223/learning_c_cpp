//
// Created by Volodymyr Avvakumov on 14.10.2024.
//
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string find_info_between_dots(string s){
    string s2(s);
    size_t firstDot = s.find('.');
    size_t lastDot = s.rfind('.');
//    assert (firstDot != lastDot);
    if (firstDot == std::string::npos && lastDot == std::string::npos){
        size_t start = s2.find_first_not_of(' ');
        if (start != string::npos) {
            s2.erase(0, start);
            return s2;
        }
    } else if (firstDot == lastDot){
        s2.erase(0, lastDot);
        return s2;
    } else {
        s2.erase(lastDot, s2.size());
        s2.erase(0, firstDot + 1);
        return s2;
    }
}

int main(){
    string s = "  afewhfuyweyuf.pip.ka.konewoinfoiewb";
    string s2 = find_info_between_dots(s);
    cout << s2 << endl;
}
