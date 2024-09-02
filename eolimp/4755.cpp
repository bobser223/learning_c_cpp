//
// Created by Volodymyr Avvakumov on 19.08.2024.
//
#include <iostream>
using namespace std;

string to13(int num, string result){
    char lst[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D'};
    if (num == 0){
        return result;
    }
    result = lst[num % 13] + result;
    return to13(num / 13, result);
}

int main(){
    string result, string1;
    int num;
    cin >> num;
    result = to13(num, string1);
    cout << result;
    return 0;
}