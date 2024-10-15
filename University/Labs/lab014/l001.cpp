//
// Created by Volodymyr Avvakumov on 14.10.2024.
//
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
    string s1("pipka");
    string s2 = "pipka";
    string s3(s1);

    cout << s3.capacity() << endl;
    cout << s3.length() << endl;
    cout << s3 << endl;
    s3.insert(1, "ggg");

    cout << s3 << endl;
    s3.erase(1, 3);
    cout << s3 << endl;
    s3.replace(1, 2, "CPP");
    cout << s3 << endl;

//    istringstream ss(s3);
//    ss << s3;
    stringstream ss;
    ss << "buerygfuiw, wehfiwepn;fjweoi, wbufehfuiweifuhewpui, fuwehfew";
    while(ss.good()){
        string s;
        ss >> s;
        cout << s << endl;
    }
    string text(ss.str());
    cout << text << endl;
    int i = 0;
    int j = 0;
    while((j = text.find(',', i)) != -1){
        cout << text.substr(i, j - i) << endl;
        i = j + 1;
    }
    return 0;
}