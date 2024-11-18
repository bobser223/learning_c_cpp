//
// Created by Volodymyr Avvakumov on 15.11.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void sort_rows_by_max(vector<vector<double>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<double>& a, const vector<double>& b) {
        return *max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end());
    });
}

void enter_matrix(vector<vector<double>>& matrix, int n, int m){
    matrix.resize(m);
    for (int i = 0; i < m; i++){
        cout << "enter " << i + 1 << " row " << endl;
        for (int j = 0; j < n; j++){
            double var;
            cin >> var;
            matrix[i].push_back(var);
        }
    }
}

void print_matrix(const vector<vector<double>>& matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (auto var: matrix[i]){
            cout << var << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cout << "enter n ";
    cin >> n;
    cout << "enter m ";
    cin >> m;
    vector<vector<double>> matrix;
    enter_matrix(matrix, n, m);
    print_matrix(matrix);
    sort_rows_by_max(matrix);
    print_matrix(matrix);
}
