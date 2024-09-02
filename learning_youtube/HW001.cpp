//
// Created by Volodymyr Avvakumov on 16.08.2024.
//
#include <iostream>

using namespace std;

int strrozmir(char *a_string){
    int i = 0;
    while(a_string[i] != '\0'){
         i++;
    }
    return i;
}

int main(){
    char s[] = "eriofjre[3iopfjiojiofjioerwjfiorejwiofjerwiopjf iofjewriofjeiowjfioerwjfioerwjiofj  jhoie jfoi jiorew jieor";
    string g = " jioerjfioerwjpgfjreiow[gjewr";
    cout << strlen(s) << endl;
    cout << strrozmir(s) << endl;

}