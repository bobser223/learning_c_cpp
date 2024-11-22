//
// Created by Volodymyr Avvakumov on 22.11.2024.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

template <class cont>
void print(const cont&c){
    cout << "[";
    for (const auto& item: c){
        cout << item << ", ";
    }
    cout << "\b\b]" << endl; // \b - delete last char
}

int main(){
    vector<int> v1 = {-6, 0, -4, 3, 7, 1, 2};
    int arr[] = {-6, 0, -4, 3, 7, 1, 2};
    sort(arr, arr + 7);
    sort(v1.begin(), v1.end());
    print(v1);
    sort(v1.begin(), v1.end(), greater<int>());
    print(v1);
    print(arr);

    cout << accumulate(v1.begin(), v1.end(), 0)  << endl;
    cout << accumulate(v1.begin(), v1.end(), 1, [](int x, int y){return x*y;})  << endl;

    cout << *find_if(v1.begin(), v1.end(), [](int x){return (x % 2 == 0);}) << endl;

    cout << inner_product(v1.begin(), v1.end(), v1.begin(), 0) << endl;

    cout << inner_product(v1.begin(), v1.end(), v1.begin(), 1, multiplies<int>(), plus<int>()) << endl;
}
