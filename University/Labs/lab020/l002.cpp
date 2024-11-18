//
// Created by Volodymyr Avvakumov on 15.11.2024.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double norma(const vector<double>& vec){
    double sum = 0;
    for (auto x: vec){
        sum += x*x;
    }
    return sqrt(sum);
}

vector<double> entering_vector(int k){
    vector<double> vec;
    vec.reserve(k);
    for (int i = 0; i < k; i++){
        double var;
        cin >> var;
        vec.push_back(var);
    }
    return vec;
}

vector<vector<double>> entering_n_vectors(int n, int k){
    vector<vector<double>> vec_vec;
    vec_vec.reserve(n);
    for (int i = 0; i < n; i++){
        vec_vec.push_back(entering_vector(k));
    }
    return vec_vec;
}

double norma_sum(int n, int k){
    vector<vector<double>> vec_vec = entering_n_vectors(n, k);
    double result;
    for (auto vec: vec_vec){
        result += norma(vec);
    }
    return result;
}

int main(){
    int n, k;
    cout << "enter n " << endl;
    cin >> n;
    cout << "enter k " << endl;
    cin >> k;
    cout << norma_sum(n, k) << endl;

}