//
// Created by Volodymyr Avvakumov on 20.08.2024.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class FileReader{

    vector<string> split(const string &str, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(str);
        while (getline(ss, token, delimiter)) {
            token.erase(remove(token.begin(), token.end(), ' '), token.end());
            token.erase(remove(token.begin(), token.end(), '\t'), token.end());
            token.erase(remove(token.begin(), token.end(), '    '), token.end());

            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

public:
    string path;
    vector<vector<string>> data;

    explicit FileReader(string a_path){
        path = a_path;
    };

    FileReader(){};

    vector<vector<string>> read(){
        ifstream fin;
        fin.open(path);
        if(!fin.is_open()){
            cout << "No file!!" << endl;
        } else {
            string str;
            while(!fin.eof()){
                str = "";
                getline(fin, str);
                vector<string> line = this-> split(str, ' ');
                data.push_back(line);
            }
        }
        return data;
        fin.close();
    };

    void print(){
        vector<vector< string>> a_data = this -> read();
        for (int i = 0; i < a_data.size(); i++){
            for (int j = 0; j < a_data[i].size(); j++) {
                cout << a_data[i][j] << " ";
            }
            cout << "" << endl;
        }

    }

};

//int main(){
//    FileReader fr("input01.txt");
////    vector<vector< string>> data = fr.read();
////    for (int i = 0; i < data.size(); i++){
////        for (int j = 0; j < data[i].size(); j++) {
////            cout << data[i][j] << " ";
////        }
////        cout << "" << endl;
////    }
//    fr.print();


//}