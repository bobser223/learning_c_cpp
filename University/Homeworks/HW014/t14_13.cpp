//
// Created by Volodymyr Avvakumov on 22.10.2024.
//
#include <iostream>
#include <string>
#include <fstream>



std::string read_file(char* filename){
    std::string text;
    std::fstream f;
    f.open(filename, f.in);

    while(f.good()){
        std::string line;
        getline(f,line);
        text += line;
        text += '\n';
    }


    f.close();
    return text;

}


char encrypt_char(char ch, int n, bool capital){
    if (capital){
        if ((int)ch + n > 90){
            return (char)((int)ch + n - 26);
        } else if ((int)ch + n < 65){
            return (char)((int)ch + n + 26);
        } else{
            return (char)((int)ch + n);
        }
    } else {
        if ((int)ch + n > 122){
            return (char)((int)ch + n - 26);
        } else if ((int)ch + n < 97){
            return (char)((int)ch + n + 26);
        } else{
            return (char)((int)ch + n);
        }
    }
}


std::string encrypt_text(const std::string text, int n){
    std::string encrypted_text;
    for (char ch: text){
        if ((int)ch >= 65 && (int)ch <= 90 ){
            char encrypted_char = encrypt_char(ch, n, true);
            encrypted_text += encrypted_char;
        } else if ((int)ch >= 97 && (int)ch <= 122){
            char encrypted_char = encrypt_char(ch, n, false);
            encrypted_text += encrypted_char;
        } else{
            encrypted_text += ch;
        }
    }

    return encrypted_text;
}


int main(){
    std::string text;
    text = read_file("input14_13.txt");
    std::cout << text << std::endl;
    int n;
    std::cin >> n;
    std::string encrypted_text = encrypt_text(text, n);
    std::cout << encrypted_text << std::endl;
    return 0;
}
