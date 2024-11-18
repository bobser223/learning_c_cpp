//
// Created by Volodymyr Avvakumov on 18.11.2024.
//
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Matrix{
private:
    vector<vector<T>> matrix;
    int n; // size matrix
    int m; // size matrix[0]

public:
    Matrix() : n(0), m(0) {}

    Matrix(int rows, int cols) : n(rows), m(cols), matrix(rows, vector<T>(cols, T())) {}

    Matrix(const vector<vector<T>>& data) : matrix(data), n(data.size()), m(data.empty() ? 0 : data[0].size()) {}

    vector<T>& operator[](int index) {
        return matrix[index];
    }

    const vector<T>& operator[](int index) const {
        return matrix[index];
    }

    template<class U>
    Matrix<T> operator+ (const Matrix<U>& other);

    template<class U>
    Matrix<T> operator* (const Matrix<U>& other) const;

    template<class U>
    vector<T> operator* (const vector<U>& vec) const;

    T& operator()(int row, int col) {
        return matrix[row][col];
    }

    const T& operator()(int row, int col) const {
        return matrix[row][col];
    }


private:
    void print(ostream& out = cout) const{
        for (auto row : matrix){
            for (auto num: row){
                out << num << ' ';
            }
            out << "\n";
        }
    }

    friend ostream& operator << (std::ostream& out, const Matrix& M) {
        M.print(out);
        return out;
    }

    static void gain_matrix(int rows, int cols, Matrix<T>& result);
};





template<typename T>
template<class U>
Matrix<T> Matrix<T>::operator+(const Matrix<U> &other) {
    if (this->matrix.size() != other.matrix.size() || this->matrix[0].size() != other.matrix[0].size())
        throw logic_error("different sizes");

    Matrix<T> result;
    gain_matrix(other.matrix.size(), other.matrix[0].size(), result);


    for (int i = 0; i < this->matrix.size(); i++){
        for (int j =0; j < this->matrix[0].size(); j++){
            result.matrix[i][j] = this->matrix[i][j] + static_cast<T>(other[i][j]);
        }
    }

    return result;
}

template<typename T>
template<class U>
Matrix<T> Matrix<T>::operator*(const Matrix<U> &other) const {
    if (this->m != other.n)
        throw logic_error("Неможливо перемножити матриці: невідповідність розмірів");

    Matrix<T> result(this->n, other.m);

    for (int i = 0; i < this->n; ++i){
        for (int j = 0; j < other.m; ++j){
            T sum = T();
            for (int k = 0; k < this->m; ++k){
                sum += this->matrix[i][k] * static_cast<T>(other.matrix[k][j]);
            }
            result.matrix[i][j] = sum;
        }
    }

    return result;
}

template<typename T>
template<class U>
vector<T> Matrix<T>::operator*(const vector<U>& vec) const {
    if (this->m != vec.size())
        throw logic_error("Неможливо перемножити матрицю на вектор: невідповідність розмірів");

    vector<T> result(this->n, T());

    for (int i = 0; i < this->n; ++i){
        for (int j = 0; j < this->m; ++j){
            result[i] += this->matrix[i][j] * static_cast<T>(vec[j]);
        }
    }

    return result;
}

template<typename T>
void Matrix<T>::gain_matrix(int rows, int cols, Matrix<T>& result) {
    result.matrix.resize(rows, vector<T>(cols, T()));
    result.n = rows;
    result.m = cols;
}


int main(){
    Matrix<int> A({
                          {1, 2, 3},
                          {4, 5, 6}
                  });
    Matrix<int> B({
                          {7, 8},
                          {9, 10},
                          {11, 12}
                  });
    Matrix<int> C = A * B;

    cout << "Матриця A:\n" << A;
    cout << "Матриця B:\n" << B;
    cout << "Матриця C = A * B:\n" << C;

    vector<int> v = {7, 8, 9};

    vector<int> result = A * v;

    cout << "Матриця A:\n" << A;
    cout << "Вектор v:\n";
    for(auto val : v) cout << val << ' ';
    cout << "\nРезультат A * v:\n";
    for(auto val : result) cout << val << ' ';
    cout << endl;

    Matrix<int> D({
                            {1,1,1},
                            {1,1,1}
    });
    cout << "Матриця A:\n" << A;
    cout << "Матриця B:\n" << D;
    cout << "Матриця C = A + B:\n" << A+D;

    return 0;
}
