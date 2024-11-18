//
// Created by Volodymyr Avvakumov on 15.11.2024.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int count_time(const vector<int>& t, int n, int i){
    if (i > n) cout << "logic err" <<endl;
    int ci_time = -i;
    for (int j = 0; j < i; j++){
        ci_time += t[j];
    }
    return ci_time;
}



int main(){
    int n;
    cout << "enter n ";
    cin >> n;
    vector<int> t;
    t.reserve(n);
    for (int i = 0; i < n; i++){
        int var;
        cin >>var;
        t[i] = var;
    }
    for (int i = 0; i < n; i++){
        cout << count_time(t, n, i) << endl;
    }
}