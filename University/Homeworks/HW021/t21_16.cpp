//
// Created by Volodymyr Avvakumov on 22.11.2024.
//
#include<iostream>
#include <vector>

template <class cont>
void print(const cont&c){
    std::cout << "[";
    for (const auto& item: c){
        std::cout << item << ", ";
    }
    std::cout << "\b\b]" << std::endl; // \b - delete last char
}

namespace bob{
    template <typename InputIt, typename OutputIt, typename UnaryOperation, typename Predicate>
    InputIt transform_if(InputIt first, InputIt last,  OutputIt result, UnaryOperation op, Predicate pred){
        if (first != result){
            while (first != last) {
                if (pred(*first)) {
                    *result++ = op(*first);
                }
                first++;
            }
            return first;
        } else {
            while (first != last) {
                if (pred(*first)) {
                    *result = op(*first);
                }
                result++;
                first++;
            }
            return first;
        }

    }

}

int main(){
    std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> vec2 = {1, 0,0,0,0,0,0};
    bob::transform_if(vec1.begin(), vec1.end(), vec1.begin(), [](int a){ return a*10;}, [](int a){ return a % 2 == 0;});
    print(vec1);
    bob::transform_if(vec1.begin(), vec1.end(), vec2.begin(), [](int a){ return a*10;}, [](int a){ return a % 2 == 0;});
    print(vec2);
}