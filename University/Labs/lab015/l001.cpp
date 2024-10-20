//
// Created by Volodymyr Avvakumov on 18.10.2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream f;
    f.open("input.txt", f.in|f.out);
    if (!f.good())
        exit(1);
    string line;
//    while(getline(f, line)){
//
//
//        cout << line << endl;
//
//    }

    while (f.good()){
        char lin[256];
        f.getline(lin, 256);
        cout << lin << endl;
    }
    f.clear();
    f.seekg(0, f.end);
    f << "\n" << 123 << ", " << 345;
    f << "pipka" << endl;
    string s;
    f >> s;
    f.close();
    return 0;
}
