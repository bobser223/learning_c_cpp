//
// Created by Volodymyr Avvakumov on 21.09.2024.
//

#include <iostream>
#include <bitset>

using namespace std;

void max_one_1(int num){
    int num_clone = num;
    int max_one_pos = 0;
    int counter = 0;
    while (num > 0){
        if (num % 2 == 1){
            max_one_pos = counter;
        }

        num = num >> 1;
        counter ++;
    }
    if (num_clone > 0){
        cout << "max one = " << max_one_pos;
        if (max_one_pos + 2 < sizeof(num_clone)*8){
            cout << ", max zero = " << (max_one_pos + 1) << endl;
        } else {
            cout << ", no max zero righter than max one (actually there is one, but it means that number is > 0 and it's number is: " << max_one_pos + 1 <<")" << endl;
        }

    } else {
        cout << "max one = " << max_one_pos << " but this bit means that number is < 0, real num bit is: " << max_one_pos -1 << endl;

    }


}

void max_one_2(int num){
    int num_clone = num;
    int max_one_pos = 0;
    int counter = 0;
    while (num > 0){
        if ((num - ((num >> 1) << 1)) == 1){
            max_one_pos = counter;
        }

        num = num >> 1;
        counter ++;
    }
    if (num_clone > 0){
        cout << "max one = " << max_one_pos;
        if (max_one_pos + 2 < sizeof(num_clone)*8){
            cout << ", max zero = " << (max_one_pos + 1) << endl;
        } else {
            cout << ", no max zero righter than max one (actually there is one, but it means that number is > 0 and it's number is: " << max_one_pos + 1 <<")" << endl;
        }

    } else {
        cout << "max one = " << max_one_pos << " but this bit means that number is < 0, real num bit is: " << max_one_pos -1 << endl;

    }


}

void max_one_3(int num){
    int num_clone = num;
    int max_one_pos = 0;
    int counter = 1;
    int changed_num = num;
    while (num == changed_num){
//        cout << std::bitset<32>(changed_num) << endl;
        changed_num = changed_num << (counter -1);
//        cout << std::bitset<32>(changed_num) << endl;
        changed_num = changed_num >> (counter -1);
//        cout << std::bitset<32>(changed_num) << endl;
        if (num != changed_num){
            break;
        }
        counter ++;
    }
    max_one_pos = sizeof(num) * 8 - counter;
    if (num_clone > 0){
        cout << "max one = " << max_one_pos;
        if (max_one_pos + 2 < sizeof(num_clone)*8){
            cout << ", max zero = " << (max_one_pos + 1) << endl;
        } else {
            cout << ", no max zero righter than max one (actually there is one, but it means that number is > 0 and it's number is: " << max_one_pos + 1 <<")" << endl;
        }

    } else {
        cout << "max one = " << max_one_pos << " but this bit means that number is < 0, real num bit is: " << max_one_pos -1 << endl;

    }


}

void max_one_bit(int num){
    int num_clone = num;
    int max_one_pos = 0;
    int counter = 0;
    while (num > 0){
        if (num % 2 == 1){
            max_one_pos = counter;
        }

        num = num >> 1;
        counter ++;
    }
    if (num_clone > 0){
        cout << "max one = " << max_one_pos;
        if (max_one_pos + 2 < sizeof(num_clone)*8){
            cout << ", max zero = " << (max_one_pos + 1) << endl;
        } else {
            cout << ", no max zero righter than max one (actually there is one, but it means that number is > 0 and it's number is: " << max_one_pos + 1 <<")" << endl;
        }

    } else {
        cout << "max one = " << max_one_pos << " but this bit means that number is < 0, real num bit is: " << max_one_pos -1 << endl;

    }



}

int main(){
    int n;
//    n = 2147483648;
    cout << "enter integer (remember that 0 in binary system doesn't have 1): "; // and -2147483648 also

    cin >> n;
//    cout << n << endl;
//    std::cout << "a bit = " <<  std::bitset<sizeof(n)*8>(n)<< std::endl;
    cout << "counting starts from zero" << endl;
    max_one_1(n);
    max_one_2(n);
    max_one_3(n);
    max_one_bit(n);

}