//
// Created by Volodymyr Avvakumov on 31.10.2024.
//

#include <string>
#include <cmath>
#include <cassert>
#include "../../course_project/dict/LinkedList_dict.h"
#include "../../course_project/dict/HashDict.h"




int get_len(const char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == ' ') continue;
        i++;
    }
    return  i;
}



void from_decimal(int num, int system, std::string& result,  const HashDict<int, char>& dict){
    if (num == 0) return;
    from_decimal(num / system,system, result, dict);
    result += dict[num % system];
}




int to_decimal(const char* symbols, int system) {
    int result = 0;
    int curr_num = 0;
    int len = get_len(symbols);

    for (int i = 0; i < len; i++) {
        char ch = symbols[i];
        if (ch >= '0' && ch <= '9') {
            curr_num = ch - '0';
        } else {
            assert(ch - 'A' <= system && "wrong system");
            curr_num = ch - 'A' + 10;
        }
        result = result * system + curr_num;
    }

    HashDict<int, char> dict;
    std::string s = "0123456789ABCDEF";
    for(int i = 0; i < 16; i++){
        dict.add(i, s[i]);
    }

    std::string check;

    from_decimal(result, system, check, dict);


    assert(check == symbols);
    return result;
}


int main(){
//    printf("%d \n", (int)'0');
//    printf("%d", (int)'9');
    HashDict<int, char> dict;

    std::string s = "0123456789ABCDEF";
    for(int i = 0; i < 16; i++){
        dict.add(i, s[i]);
    }

    std::string result;

    from_decimal(100,15, result, dict);
    printf("%d\n",to_decimal("623C01", 16));
    std::cout << result << std::endl;
//    printf("%d",to_decimal("1010", 2));
}